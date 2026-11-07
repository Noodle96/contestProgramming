/*
==========================================================
|  Archivo       : C_Cellular_Network.cpp
|  Autor         : Russell
|  Fecha         : 2026-11-07 12:13
|--------------------------------------------------------
|  Tópicos utilizados:
|  - binary search
|  - training
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

void solve() {
    int n,m;
    cin >> n >> m;
    vector<ll> cities(n), towers(m);
    for (auto &x : cities) cin >> x;
    for (auto &y : towers) cin >> y;


    auto can = [&](ll r) -> bool {
        vector<ll> alcance;
        for (auto tower: towers) alcance.pb(tower + r);
        for (auto city: cities) {
            auto it = lower_bound(all(alcance), city);
            if(it == alcance.end()){
                return false;
            }
            if(city < *it -2*r){
                return false;
            }
        }
        return true;
    };

    ll l = 0;
    ll r = 1e12;
    ll ans = -1;
    while(l <= r){
        ll mid = l + (r - l) / 2;
        if(can(mid)){
            ans = mid;
            r = mid - 1; // izquierda
        }else{
            l = mid + 1; // derecha
        }
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