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
      build(r(p), m + 1, R);
      st[p] = st[l(p)] + st[r(p)];
    }
  }

  void propagate(int p, int L, int R) {
    if (lazy[p] != -1) {
      st[p] = (R - L + 1) * lazy[p];  // Aplica la actualización (1 o 0)
      if (L != R) { // Propagar solo si no es una hoja
        lazy[l(p)] = lazy[p]; 
        lazy[r(p)] = lazy[p]; 
      }
      lazy[p] = -1; // Limpiar el lazy
    }
  }

  void update_range(int p, int L, int R, int i, int j, int val) {
    propagate(p, L, R);

    if (i > j) return;
    if (L > j || R < i) return; // Fuera del rango de actualización

    if (L >= i && R <= j) { 
      lazy[p] = val;
      propagate(p, L, R);
    } else {
      int m = (L + R) / 2;
      update_range(l(p), L, m, i, min(m, j), val);
      update_range(r(p), m + 1, R, max(i, m + 1), j, val);
      st[p] = st[l(p)] + st[r(p)];
    }
  }

  int count_ones(int p, int L, int R, int i, int j) {
    propagate(p, L, R);

    if (L > j || R < i) return 0; // Fuera del rango
    if (L >= i && R <= j) return st[p]; // Dentro del rango, devolver el conteo

    int m = (L + R) / 2;
    return count_ones(l(p), L, m, i, j) + count_ones(r(p), m + 1, R, i, j);
  }

public:
  SegmentTree(int sz) : n(sz), A(n), st(4*n), lazy(4*n, -1) {}

  SegmentTree(const vi &initialA) : SegmentTree((int)initialA.size()) {
    A = initialA;
    build(1, 0, n - 1);
  }

  void update_range(int i, int j, int val) { update_range(1, 0, n - 1, i, j, val); }

  int count_ones(int i, int j) { return count_ones(1, 0, n - 1, i, j); }
};

int main() {
  vi A = {0, 1, 0, 1, 1, 0, 0, 1}; 
  SegmentTree st(A);

  cout << "Número de unos en [0, 7]: " << st.count_ones(0, 7) << endl; // 4
  cout << "Número de unos en [1, 4]: " << st.count_ones(1, 4) << endl; // 3

  st.update_range(2, 5, 1); // Convertimos A[2..5] en unos
  cout << "Después de la actualización, número de unos en [0, 7]: " << st.count_ones(0, 7) << endl; // 6

  return 0;
}
