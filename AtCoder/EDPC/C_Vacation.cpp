/*
==========================================================
|  Archivo       : C_Vacation.cpp
|  Autor         : Russell
|  Fecha         : 2026-09-11 19:45
|--------------------------------------------------------
|  Tópicos utilizados:
|  - sorting
|  - training
|  - greedy
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
    int n;
    cin >> n;
    vector< vector<ll> > H(n, vector<ll>(3,0));
    for(int i = 0; i < n; i++){
        cin >> H[i][0] >> H[i][1] >> H[i][2];
    }
    vector< vector<ll> > dp(n, vector<ll>(3,0));
    dp[0][0] = H[0][0];
    dp[0][1] = H[0][1];
    dp[0][2] = H[0][2];
    for(int i = 1; i < n; i++){
        dp[i][0] = max(dp[i-1][1] + H[i][0],
                    dp[i-1][2] + H[i][0]);
        dp[i][1] = max(dp[i-1][0] + H[i][1],
                    dp[i-1][2] + H[i][1]);
        dp[i][2] = max(dp[i-1][0] + H[i][2],
                    dp[i-1][1] + H[i][2]);
    }
    ll ans = -INF;
    for(int i = 0; i < 3; i++){
        ans = max(dp[n-1][i], ans);
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