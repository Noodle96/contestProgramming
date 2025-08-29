/*
==========================================================
|  Archivo       : B_Ilya_and_Queries.cpp
|  Autor         : Russell
|  Fecha         : 2025-08-28 18:07
|--------------------------------------------------------
|  Tópicos utilizados:
|  - *1100
|  - dp 
|  - implementation
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
    string str; cin >> str;
    int n = (int)str.size();
    int q; cin >> q;
    // dp[i] = s[i-1] == s[i] hasta el indice i
    vector<int> dp(n,0);
    for(int e =  1; e < n; e++)
        dp[e] = dp[e-1] + (str[e-1] == str[e] ? 1 : 0);
    while(q--){
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << dp[r] - dp[l] << "\n";
    }
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