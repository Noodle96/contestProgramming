/*
==========================================================
|  Archivo       : F_Final_Boss.cpp
|  Autor         : Russell
|  Fecha         : 2026-04-06 17:56
|--------------------------------------------------------
|  Tópicos utilizados:
|  - binary search
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
    ll h; cin >> h;
    int n; cin >> n;

    vector<int> a(n), c(n);
    for(int i =0 ; i < n; i++){
        cin >> a[i];
    }
    for(int i =0 ; i < n; i++){
        cin >> c[i];
    }

    auto can = [&](ll turn) -> bool {
        ll total = 0;
        for(int i = 0; i < n; i++){
            total += (ll)a[i] * ceildiv(turn, (ll)c[i]);
            if(total >= h) return true;
        }
        return false;
    };

    ll l = 0, r = 4e10;
    ll ans = 0;
    while(l <= r){
        ll mid = l + (r - l) / 2;
        if(can(mid)){
            ans = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
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