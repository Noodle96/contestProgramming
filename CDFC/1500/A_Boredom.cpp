/*
==========================================================
|  Archivo       : A_Boredom.cpp
|  Autor         : Russell
|  Fecha         : 2026-03-06 17:11
|--------------------------------------------------------
|  Tópicos utilizados:
|  - dp
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

const int N = 1e5 +5;

void solve() {
    int n; cin >> n;
    vector<ll> dp(N+1, 0);
    vector<ll> cnt(N+1,0);
    for(int i = 0 ;i < n; i++){
        ll a; cin >> a;
        cnt[a]++;
    }
    dp[0] = 0;
    dp[1] = 1 * cnt[1];
    for(int i = 2; i <= N; i++){
        ll take_i = dp[i-2] + cnt[i] * i;
        ll dont_take_i = dp[i-1];
        dp[i] = max(take_i, dont_take_i);
    }
    cout << dp[N] << "\n";
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