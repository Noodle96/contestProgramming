/*
==========================================================
|  Archivo       : B_Yet_Another_Coin_Problem.cpp
|  Autor         : Russell
|  Fecha         : 2026-09-29 13:14
|--------------------------------------------------------
|  Tópicos utilizados:
|  - dp
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
const unsigned int N = 1e3;
ll dp[N];
const int COINS[5] = {1, 3, 6, 10, 15};
const int CONST[15] = {+0, +1, +2, +1, +2, +1, +1, +2, +2, +2, +1, +2, +2, +2, +3};
void precompute(){
    for(int i = 0; i < N; i++ ) dp[i] = INF;
    dp[0] = 0;
    for(int i = 1; i < N; i++){
        for(auto c: COINS){
            if(i >= c && dp[i - c] != INF){
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    } 
}

void solve() {
    ll n;
    cin >> n;
    if(n < N){
        cout << dp[n] << "\n";
        return;
    }else{
        ll ans = n / 15;
        int rs = n % 15;
        ans += CONST[rs];
        cout << ans << "\n"; 

    }
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
    precompute();
    while (t--) {
        solve();
    }
    return 0;
}