#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class SegmentTree {
private:
  int n;
  vi A, st, lazy; 

  int l(int p) { return p << 1; }   
  int r(int p) { return (p << 1) + 1; }    

  int conquer(int a, int b) { return a + b; } // Ahora hacemos la suma

  void build(int p, int L, int R) { // Construcción en O(n)
    if (L == R)
      st[p] = A[L]; 
    else {
      int m = (L + R) / 2;
      build(l(p), L, m);
      build(r(p), m+1, R);
      st[p] = conquer(st[l(p)], st[r(p)]);
    }
  }

  void propagate(int p, int L, int R) {
    if (lazy[p] != 0) { // Si hay un valor pendiente por propagar
      st[p] += (R - L + 1) * lazy[p]; // Sumar el valor al rango completo
      if (L != R) { // Si no es hoja, propagar a los hijos
        lazy[l(p)] += lazy[p];
        lazy[r(p)] += lazy[p];
      }
      lazy[p] = 0; // Limpiar el nodo actual
    }
  }

  int RSQ(int p, int L, int R, int i, int j) {
    propagate(p, L, R); // Aplicar Lazy Propagation
    if (i > j) return 0; // Si el rango es inválido
    if (L >= i && R <= j) return st[p]; // Si el segmento está completamente dentro del rango

    int m = (L + R) / 2;
    return conquer(RSQ(l(p), L, m, i, min(m, j)), 
                   RSQ(r(p), m+1, R, max(i, m+1), j));
  }

  void update(int p, int L, int R, int i, int j, int val) {
    propagate(p, L, R); // Aplicar Lazy Propagation
    if (i > j) return;
    if (L >= i && R <= j) { // Si el segmento está completamente dentro del rango
      lazy[p] += val; // Marcar para actualización diferida
      propagate(p, L, R); // Aplicar la actualización de inmediato
    }
    else {
      int m = (L + R) / 2;
      update(l(p), L, m, i, min(m, j), val);
      update(r(p), m+1, R, max(i, m+1), j, val);
      st[p] = conquer(st[l(p)], st[r(p)]); // Recalcular el nodo padre
    }
  }

public:
  SegmentTree(int sz) : n(sz), A(n), st(4*n), lazy(4*n, 0) {}

  SegmentTree(const vi &initialA) : SegmentTree((int)initialA.size()) {
    A = initialA;
    build(1, 0, n-1);
  }

  void update(int i, int j, int val) { update(1, 0, n-1, i, j, val); }

  int RSQ(int i, int j) { return RSQ(1, 0, n-1, i, j); }
};

int main() {
  vi A = {1, 3, 5, 7, 9, 11}; 
  SegmentTree st(A);

  printf("RSQ(1, 3) = %d\n", st.RSQ(1, 3)); // 3 + 5 + 7 = 15
  printf("RSQ(0, 5) = %d\n", st.RSQ(0, 5)); // 1 + 3 +1 5 + 7 + 9 + 11 = 36
  
  st.update(1, 3, 2); // Incrementamos los valores en el rango [1, 3] en +2
  printf("RSQ(1, 3) after update = %d\n", st.RSQ(1, 3)); // Ahora es 5 + 7 + 9 = 21
  
  printf("RSQ(0, 5) after update = %d\n", st.RSQ(0, 5)); // Aho1ra es 1 + 5 + 7 + 9 + 9 + 11 = 42

  return 0;
}
