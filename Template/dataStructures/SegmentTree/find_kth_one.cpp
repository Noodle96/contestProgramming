#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class SegmentTree {
private:
  int n;
  vi A, st;

  int l(int p) { return p << 1; }    
  int r(int p) { return (p << 1) + 1; }    

  void build(int p, int L, int R) { // Construcción en O(n)
    if (L == R)
      st[p] = A[L]; // Nodo hoja almacena 1 si A[L] = 1, sino 0
    else {
      int m = (L + R) / 2;
      build(l(p), L, m);
      build(r(p), m+1, R);
      st[p] = st[l(p)] + st[r(p)]; // Sumar los 1s de los hijos
    }
  }

  void update(int p, int L, int R, int idx, int val) {
    if (L == R) { // Nodo hoja
      st[p] = val; 
    }
    else {
      int m = (L + R) / 2;
      if (idx <= m)
        update(l(p), L, m, idx, val);
      else
        update(r(p), m+1, R, idx, val);
      st[p] = st[l(p)] + st[r(p)];
    }
  }

  int find_kth_one(int p, int L, int R, int k) {
    if (L == R) return L; // Encontramos la posición del k-ésimo 1
    int m = (L + R) / 2;
    if (st[l(p)] >= k)
      return find_kth_one(l(p), L, m, k); // Buscar en la izquierda
    else
      return find_kth_one(r(p), m+1, R, k - st[l(p)]); // Buscar en la derecha
  }

public:
  SegmentTree(int sz) : n(sz), A(n), st(4*n) {}

  SegmentTree(const vi &initialA) : SegmentTree((int)initialA.size()) {
    A = initialA;
    build(1, 0, n-1);
  }

  void update(int idx, int val) { update(1, 0, n-1, idx, val); }

  int find_kth_one(int k) { return find_kth_one(1, 0, n-1, k); }
};

int main() {
  vi A = {0, 1, 0, 1, 1, 0, 0, 1}; 
  SegmentTree st(A);

  printf("El 1º uno está en la posición: %d\n", st.find_kth_one(1)); // 1
  printf("El 2º uno está en la posición: %d\n", st.find_kth_one(2)); // 3
  printf("El 3º uno está en la posición: %d\n", st.find_kth_one(3)); // 4
  printf("El 4º uno está en la posición: %d\n", st.find_kth_one(4)); // 7

  st.update(2, 1); // Convertimos A[2] de 0 a 1
  printf("Después de la actualización:\n");
  printf("El 1º uno está en la posición: %d\n", st.find_kth_one(1)); // 1
  printf("El 2º uno está en la posición: %d\n", st.find_kth_one(2)); // 2
  printf("El 3º uno está en la posición: %d\n", st.find_kth_one(3)); // 3
  printf("El 4º uno está en la posición: %d\n", st.find_kth_one(4)); // 4
  printf("El 5º uno está en la posición: %d\n", st.find_kth_one(5)); // 7

  return 0;
}
