/*
==========================================================
|  Archivo       : A_Vacations.cpp
|  Autor         : Russell
|  Fecha         : 2026-09-15 11:29
|--------------------------------------------------------
|  Tópicos utilizados:
|  - dp
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
    int n;
    cin >> n;
    vector<int> sts(n,0);
    for(int i = 0; i < n; i++){
        cin>> sts[i];
    }
    vector<vector<bool>> m_sts(n, vector<bool>(2,false));
    for(int i = 0; i < n; i++){
        if(sts[i] == 2 || sts[i] == 3){
            m_sts[i][0] = true;
        }
        if(sts[i] == 1 || sts[i] == 3){
            m_sts[i][1] = true;
        }
    }
    
    /*
        dp[i][j] = el menor numero de de dias de descanso desde el dia 1 hasta el dia i, considerando que estamos en el estado j.
            j = 0, descanso ese dia
            j = 1, se hace deporte
            j = 2, se hace contest
    */
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    // caso base
    dp[0][0] = 1;   // Siempre se descansa el dia 1
    dp[0][1] = (m_sts[0][0] ? 0: INF);  // 0 si el gym esta abierto, sino INF 
    dp[0][2] = (m_sts[0][1] ? 0 : INF); // 0 si se hara contest, sino INF
    for(int i = 1; i < n; i++){
        dp[i][0] = min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2])) + 1;
        ll one = min(dp[i-1][0], dp[i-1][2]);
        dp[i][1] = (m_sts[i][0] ? one : INF);
        ll two = min(dp[i-1][0], dp[i-1][1]);
        dp[i][2] = (m_sts[i][1] ? two : INF);
    }
    


    ll ans = min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
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