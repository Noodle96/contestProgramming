#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class SegmentTree {
private:
  int n;
  vi A, st;

  int l(int p) { return p << 1; }   
  int r(int p) { return (p << 1) + 1; }    

  int conquer(int a, int b) { return __gcd(a, b); } // Usamos GCD en lugar de suma

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

  int RGCDQ(int p, int L, int R, int i, int j) {
    if (i > j) return 0; // Si el rango es inválido
    if (L >= i && R <= j) return st[p]; // Si el segmento está completamente dentro del rango

    int m = (L + R) / 2;
    return conquer(RGCDQ(l(p), L, m, i, min(m, j)), 
                   RGCDQ(r(p), m+1, R, max(i, m+1), j));
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
      st[p] = conquer(st[l(p)], st[r(p)]);
    }
  }

public:
  SegmentTree(int sz) : n(sz), A(n), st(4*n) {}

  SegmentTree(const vi &initialA) : SegmentTree((int)initialA.size()) {
    A = initialA;
    build(1, 0, n-1);
  }

  int RGCDQ(int i, int j) { return RGCDQ(1, 0, n-1, i, j); }

  void update(int idx, int val) { update(1, 0, n-1, idx, val); }
};

int main() {
  vi A = {2, 3, 6, 9, 5}; 
  SegmentTree st(A);

  printf("GCD(1, 3) = %d\n", st.RGCDQ(1, 3)); // GCD(3,6,9) = 3
  printf("GCD(0, 4) = %d\n", st.RGCDQ(0, 4)); // GCD(2,3,6,9,5) = 1
  
  st.update(2, 4); // Cambiamos A[2] de 6 a 4
  printf("GCD(1, 3) after update = %d\n", st.RGCDQ(1, 3)); // Ahora GCD(3,4,9) = 1
  
  printf("GCD(0, 4) after update = %d\n", st.RGCDQ(0, 4)); // Ahora GCD(2,3,4,9,5) = 1

  return 0;
}
