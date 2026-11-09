/*
==========================================================
|  Archivo       : C_Hamburgers.cpp
|  Autor         : Russell
|  Fecha         : 2026-11-09 14:08
|--------------------------------------------------------
|  Tópicos utilizados:
|  - binary search
|  - training
|  - *1600
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
    string s;
    cin >> s;
    array<ll, 3> need = {0, 0, 0};
    for (char c: s) {
        if (c == 'B') need[0]++;
        else if (c == 'S') need[1]++;
        else need[2]++;
    }

    array<ll, 3> have;
    for (auto &x: have) cin >> x;
    
    array<ll, 3> price;
    for (auto &x: price) cin >> x;

    ll r;
    cin >> r;
    ll totalSandwiches = 0;
    ll mn = INF;
    for (auto i = 0; i < 3; i++){
        if (need[i] == 0) continue;
        mn = min(mn, floordiv(have[i], need[i]));
    }
    totalSandwiches += mn;
    //update have;
    for(int i = 0; i < 3; i++){
        have[i] -= mn * need[i];
    }

    auto can = [&](ll quantity) -> bool {
        ll r_temp = r;
        for (auto i = 0; i < 3; i++){
            ll required = need[i] * quantity;
            if (required > have[i]){
                ll toBuy = required - have[i];
                ll cost = toBuy * price[i];
                if (cost > r_temp) return false;
                r_temp -= cost;
            }
        }
        return true;
    };

    ll l = 0;
    ll r_ = 1e13;
    ll ans = -1;
    while (l <= r_){
        ll mid = l + (r_ - l) / 2;
        if (can(mid)){ // encontrar el maximo valido
            ans = mid;
            l = mid + 1; // derecha;
        }else{
            r_ = mid - 1; // izquierda;
        }
    }
    ans += totalSandwiches;
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