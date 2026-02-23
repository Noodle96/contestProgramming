/*
==========================================================
|  Archivo       : Population.cpp
|  Autor         : Russell
|  Fecha         : 2026-02-21 14:04
|--------------------------------------------------------
|  Tópicos utilizados:
|  - number theory
|  - training
|  - Lev 2
==========================================================
*/

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;
using i64 = int64_t;
using i32 = int32_t;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vll = vector<ll>;

#define pb push_back
#define mp make_pair

const int INF = 1e9;

ll gcd(ll a, ll b) {
    if (a % b == 0) return b;
    else return gcd(b, a % b);
}

ll floordiv(ll a, ll b) {
    if (a >= 0) return a / b;
    return - ( (-a + b - 1) / b );
}

ll ceildiv(ll a, ll b) {
    // ceil(a/b) = -floor((-a)/b)
    if (a >= 0) return (a + b - 1) / b;
    return - ( (-a) / b );
}

int bitlen_unsigned(unsigned long long n) {
    // __builtin_clzll: Cuenta los ceros a la izquierda
    return (n == 0) ? 1 : 64 - __builtin_clzll(n);
}

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}


class SegmentTree
{
private:
    int n;
    vector<ll> A, st, lazy;

    int l(int p) { return p << 1; }
    int r(int p) { return (p << 1) + 1; }

    ll conquer(ll a, ll b) { return a + b; } // Ahora hacemos la suma

    void build(int p, int L, int R)
    { // Construcción en O(n)
        if (L == R)
            st[p] = A[L];
        else
        {
            int m = (L + R) / 2;
            build(l(p), L, m);
            build(r(p), m + 1, R);
            st[p] = conquer(st[l(p)], st[r(p)]);
        }
    }

    void propagate(int p, int L, int R)
    {
        if (lazy[p] != 0)
        {                                   // Si hay un valor pendiente por propagar
            st[p] += (R - L + 1) * lazy[p]; // Sumar el valor al rango completo
            if (L != R)
            { // Si no es hoja, propagar a los hijos
                lazy[l(p)] += lazy[p];
                lazy[r(p)] += lazy[p];
            }
            lazy[p] = 0; // Limpiar el nodo actual
        }
    }

    ll RSQ(int p, int L, int R, int i, int j)
    {
        propagate(p, L, R); // Aplicar Lazy Propagation
        if (i > j)
            return 0; // Si el rango es inválido
        if (L >= i && R <= j)
            return st[p]; // Si el segmento está completamente dentro del rango

        int m = (L + R) / 2;
        return conquer(RSQ(l(p), L, m, i, min(m, j)),
                       RSQ(r(p), m + 1, R, max(i, m + 1), j));
    }

    void update(int p, int L, int R, int i, int j, ll val)
    {
        propagate(p, L, R); // Aplicar Lazy Propagation
        if (i > j)
            return;
        if (L >= i && R <= j)
        {                       // Si el segmento está completamente dentro del rango
            lazy[p] += val;     // Marcar para actualización diferida
            propagate(p, L, R); // Aplicar la actualización de inmediato
        }
        else
        {
            int m = (L + R) / 2;
            update(l(p), L, m, i, min(m, j), val);
            update(r(p), m + 1, R, max(i, m + 1), j, val);
            st[p] = conquer(st[l(p)], st[r(p)]); // Recalcular el nodo padre
        }
    }

public:
    SegmentTree(int sz) : n(sz), A(n), st(4 * n), lazy(4 * n, 0) {}

    SegmentTree(const vector<ll> &initialA) : SegmentTree((int)initialA.size())
    {
        A = initialA;
        build(1, 0, n - 1);
    }

    void update(int i, int j, ll val) { update(1, 0, n - 1, i, j, val); }

    ll RSQ(int i, int j) { return RSQ(1, 0, n - 1, i, j); }
};

void solve() {
    int n; cin >> n;
    vector<ll> A(n);
    for(int i = 0 ;i < n ; i++){
        cin >> A[i];
    }
    SegmentTree st(A);

    int q; cin >> q;
    while(q--){
        char type; cin >> type;
        if(type == 'U'){
            int l; cin >> l;
            l--;
            ll val; cin >> val;
            st.update(l, l, val);
        }else{ // type == 'R'
            int l, r; cin >> l >> r;
            l--, r--;
            cout << st.RSQ(l, r) << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;
    // cin >> t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}