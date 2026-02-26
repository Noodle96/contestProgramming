/*
==========================================================
|  Archivo       : D_Place_of_the_Olympiad.cpp
|  Autor         : Russell
|  Fecha         : 2026-02-26 15:03
|--------------------------------------------------------
|  Tópicos utilizados:
|  - binary search
|  - implementation
|  - training
|  - *1200
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
    ll n, m, k;
    cin >> n >> m >> k;
    ll l = 1;
    ll r = m;
    ll ans = -1;

    // Select the best v
    ll v =  ceildiv(k, n);


    auto can = [&](ll x) -> bool {
        ll b1 = v / x;
        ll b2 = v % x;
        ll g = x * b1;
        if(b2 == 0){
            if(b1 > 1) g += (b1 - 1);
        }else{
            g += b1;
            g += b2;
        }
        return m >= g;
    };

    while(l <= r){
        ll mid = l + (r - l ) / 2;
        if(can(mid)){
            ans = mid;
            // cout << "izquierda: " << ans << "\n\n";
            r  = mid - 1;
        }else{
            l = mid  + 1;
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
    cin >> t;
    // t = 1;
    while (t--) {
        solve();
    }
    return 0;
}