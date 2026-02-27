/*
==========================================================
|  Archivo       : C_Maximum _Median.cpp
|  Autor         : Russell
|  Fecha         : 2026-02-27 11:05
|--------------------------------------------------------
|  Tópicos utilizados:
|  - binary search
|  - sorting
|  - *1400
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
    int n; cin >> n;
    ll k; cin >> k;
    vector<ll> a(n);
    for(int i = 0; i <  n; i++) cin >> a[i];
    ll m = n / 2;
    sort(all(a));

    auto can = [&](ll x) -> bool {
        ll cost = 0;
        for(int i = m; i < n ; i++){
            cost += (x - a[i]);
            if(cost > k) return false;
        }
        return  k >= cost;
    }; 

    ll l = 1;
    ll r = 1e18;
    ll ans = -1;
    while(l <= r){
        ll mid = l + (r - l) / 2;
        if(can(mid)){
            ans = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
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