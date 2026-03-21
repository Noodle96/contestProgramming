/*
==========================================================
|  Archivo       : bit.cpp
|  Autor         : Russell
|  Fecha         : 2026-03-20 17:21
|--------------------------------------------------------
|  Tópicos utilizados:
|  - femwick tree
|  - training
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


class Fenwick{
    private:
        int n;
        vector<ll> bit;
    public:
        Fenwick(int n): n(n), bit(n+1, 0){}
        void update(int idx, ll val){
            while(idx <= n){
                bit[idx] += val;
                idx += (idx & -idx);
            }
        }
        ll query(int idx){
            ll sum = 0;
            while(idx > 0){
                sum += bit[idx];
                idx -= (idx & -idx);
            }
            return sum;
        }
        ll query(int l, int r){
            return query(r) - query(l-1);
        }
};

/*
    (PREFI SUM DINAMICO)
    Tenemos un arreglo de n elementos, debemos procesar operaciones
    1 i x:  sumar x a a[i]
    2 l r: imprimit suma de [l,r]
    Input:
    5 5
    1 1 2
    1 3 5
    2 1 3
    1 5 1
    2 1 5
*/

void problem1(){
    int n,m;
    cin >> n >> m;
    Fenwick ft(n);
    for(int j = 0; j < m; j++){
        int type; cin >> type;
        if(type == 1){
            int i;
            ll x;
            cin >> i >> x;
            ft.update(i, x);
        }else{
            // type = 2
            int l, r;
            cin >> l >> r;
            ll ans = ft.query(l,r);
            cout << ans << "\n";
        }
    }
}

/*
    2. Inversion Count
    Idea:
        contar pares i < j y a[i] > a [j]
    Problema:
        Dado un arreglo, contar cuántas inversiones tiene.
    Input:
        5
        3 1 2 5 4
    Output:
        3

*/
void problem2(){
    int n;
    cin >> n;
    vector<ll> vec(n);
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }

    // Implementacion con compresion
    auto inversion_count = [&]() -> int {
        vector<ll> vals = vec;
        sort(all(vals));
        vals.erase(unique(all(vals)), vals.end());
        auto get_id = [&](ll x) -> int {
            return lower_bound(all(vals), x) - vals.begin() + 1;
        };

        Fenwick ft(vals.size());
        ll ans = 0;
        for(int i = n -1; i >= 0; i--){
            int id = get_id(vec[i]);
            ans += ft.query(id); // <=
            ft.update(id, +1);
        }
        return ans;
    };

    auto ans = inversion_count();
    cout << ans << "\n";
}


void intervals(){
    int n = 100;
    // [ i − (i & − i) + 1, i ]
    for(int i = 1; i <= n; i++){
        int l = i - (i&-i) + 1;
        int r = i;
        cout << "[" << l << "," << r << "]\n";
    }
}

void solve() {
    intervals();
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
        // solve();
        // problem1();
        problem2();
    }
    return 0;
}