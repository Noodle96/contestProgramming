/*
==========================================================
|  Archivo       : A_Cut_Ribbon.cpp
|  Autor         : Russell
|  Fecha         : 2025-06-09 12:59
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

const int INF = 1e9;

ll gcd(ll a,ll b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

void solve(){
    int n,a,b,c;
    cin >> n >> a >> b >> c;
    // dp[i] = maximum number of pieces that can be obtained with a ribbon of length i
    vector<int> dp(n+1, -INF);
    dp[0] = 0; // Base case: 0 length ribbon can be achieved with 0 cuts
    for(int e = 1; e <= n; e++){
        if(e >= a) dp[e] = max(dp[e], dp[e-a]+1);
        if(e >= b) dp[e] = max(dp[e], dp[e-b]+1);
        if(e >= c) dp[e] = max(dp[e], dp[e-c]+1);
    }
    cout << dp[n] << '\n';
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