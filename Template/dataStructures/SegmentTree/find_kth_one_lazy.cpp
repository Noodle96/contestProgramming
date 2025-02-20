#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class SegmentTree {
private:
  int n;
  vi A, st, lazy;

  int l(int p) { return p << 1; }
  int r(int p) { return (p << 1) + 1; }

  void build(int p, int L, int R) {
    if (L == R)
      st[p] = A[L]; 
    else {
      int m = (L + R) / 2;
      build(l(p), L, m);
      build(r(p), m+1, R);
      st[p] = st[l(p)] + st[r(p)];
    }
  }

  void propagate(int p, int L, int R) {
    if (lazy[p] != -1) {  // Si hay una actualización pendiente
      st[p] = (R - L + 1) * lazy[p]; // Si lazy[p] = 1, llena el rango con 1s; si es 0, llena con 0s
      if (L != R) {
        lazy[l(p)] = lazy[p]; 
        lazy[r(p)] = lazy[p]; 
      }
      lazy[p] = -1; 
    }
  }

  void update_range(int p, int L, int R, int i, int j, int val) {
    propagate(p, L, R);
    if (i > j) return;
    
    if (L >= i && R <= j) { 
      lazy[p] = val;
      propagate(p, L, R);
    } else {
      int m = (L + R) / 2;
      update_range(l(p), L, m, i, min(m, j), val);
      update_range(r(p), m+1, R, max(i, m+1), j, val);
      st[p] = st[l(p)] + st[r(p)];
    }
  }

  int find_kth_one(int p, int L, int R, int k) {
    propagate(p, L, R);
    if (L == R) return L;

    int m = (L + R) / 2;
    propagate(l(p), L, m);
    propagate(r(p), m+1, R);

    if (st[l(p)] >= k)
      return find_kth_one(l(p), L, m, k);
    else
      return find_kth_one(r(p), m+1, R, k - st[l(p)]);
  }

public:
  SegmentTree(int sz) : n(sz), A(n), st(4*n), lazy(4*n, -1) {}

  SegmentTree(const vi &initialA) : SegmentTree((int)initialA.size()) {
    A = initialA;
    build(1, 0, n-1);
  }

  void update_range(int i, int j, int val) { update_range(1, 0, n-1, i, j, val); }

  int find_kth_one(int k) { return find_kth_one(1, 0, n-1, k); }
};

int main() {
  vi A = {0, 1, 0, 1, 1, 0, 0, 1}; 
  SegmentTree st(A);

  printf("El 2º uno está en la posición: %d\n", st.find_kth_one(2)); // 3

  st.update_range(0, 3, 1); // Poner en 1 los valores de A[0] a A[3]
  printf("Después de la actualización en rango (0,3):\n");
  printf("El 2º uno está en la posición: %d\n", st.find_kth_one(2)); // 1
  printf("El 4º uno está en la posición: %d\n", st.find_kth_one(4)); // 3
  printf("El 5º uno está en la posición: %d\n", st.find_kth_one(5)); // 4

  return 0;
}
