/*
==========================================================
|  Archivo       : Awkward.cpp
|  Autor         : Russell
|  Fecha         : 2025-07-26 16:43
|--------------------------------------------------------
|  Tópicos utilizados:
|  - DP
==========================================================
*/

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;

using ll = long long;
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

const ll INF = 1e18;

ll gcd(ll a,ll b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

void solve(){
    int n;
    ll b;
    cin >> n >> b;

    // dp[l][r]: coste mínimo en el peor caso para rango [l..r]
    static ll dp[401][401];
    // Inicializar casos base: dp[l][l] = l
    for (int i = 1; i <= n; i++) {
        dp[i][i] = i;
    }
    // Para intervalos de longitud >= 2
    for (int len = 2; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            ll best = LLONG_MAX;
            // Probar cada puja x en [l..r]
            for (int x = l; x <= r; x++) {
                ll leftCost  = (x > l ? x + dp[l][x-1] : x);
                ll rightCost = (x < r ? b + dp[x+1][r]  : 0);
                ll worst     = max(leftCost, rightCost);
                best = min(best, worst);
            }
            dp[l][r] = best;
        }
    }

    cout << dp[1][n] << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    solve();
    return 0;
}