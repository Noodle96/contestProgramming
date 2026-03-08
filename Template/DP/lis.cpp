/*
==========================================================
|  Archivo       : lis.cpp
|  Autor         : Russell
|  Fecha         : 2026-03-07 22:34
|--------------------------------------------------------
|  Tópicos utilizados:
|  - LIS: Longest Increasing Subsequence
|  - dp
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
    vector<int> v = {8, 3, 4, 6, 5, 2, 0, 7, 9, 1};
    
    // Complejidad O(n^2)
    // retorna solo el len de lis
    auto lis = [&](vector<int> &a) -> int{
        int n = (int)a.size();
        vector<int> dp(n, 1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(a[i] > a[j]){
                    dp[i] = max(dp[i], dp[j] +  1);
                }
            }
        }
        cout << "print dp\n";
        for(int i = 0;  i < n; i++){
            cout << dp[i] << " ";
        } cout << "\n";
        int ans = dp[0];
        for(int i = 1; i < n; i++){
            ans = max(ans, dp[i]);
        }
        return ans;
    };

    int longestIS = lis(v);
    cout << longestIS << "\n";


    cout << "return the subsequence\n";
    // Complejidad O(n^2)
    // Retorna la subsequencia
    auto lis2 = [&](vector<int> &vec) -> vector<int> {
        int n = (int)vec.size();
        vector<int> dp(n, 1);
        vector<int> p(n, -1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(vec[i] > vec[j] && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                    p[i] = j;
                }
            }
        }
        // encontrar el maximo de dp[i] y el i del ultimo de la subsecuencia
        int ans = dp[0];
        int pos = 0;
        for(int i = 1; i < n; i++){
            if(dp[i] > ans){
                ans = dp[i];
                pos = i;
            }
        }
        // Reconstruir la subsecuence
        vector<int> path;
        while(pos != -1){
            path.pb(vec[pos]);
            pos = p[pos];
        }
        reverse(all(path));
        return path;
    };

    auto subsecuence = lis2(v);
    for(auto sb: subsecuence){
        cout << sb << " ";
    }cout << "\n";
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