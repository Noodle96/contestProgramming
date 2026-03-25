/*
==========================================================
|  Archivo       : C_Little_Girl_and_Maximum_Sum.cpp
|  Autor         : Russell
|  Fecha         : 2026-03-25 12:18
|--------------------------------------------------------
|  Tópicos utilizados:
|  - data structures: fenwick tree
|  - sorting
|  - *1500
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
                idx += (idx  & -idx);
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

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(all(a), [&](ll x, ll y){
        return x > y;
    });
    
    Fenwick ft(n);
    
    while(q--){
        int l,r;
        cin >> l >> r;
        ft.update(l, +1);
        if(r+1 <= n){
            ft.update(r+1, -1);
        }
    }
    vector<ll> freq;
    for(int i = 1; i <= n; i++){
        freq.push_back(ft.query(i));
    }
    sort(all(freq), [&](ll x, ll y){
        return x > y;
    });
    
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += freq[i] * a[i];
    }
    cout << ans << "\n";

    
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