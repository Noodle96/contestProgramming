/*
==========================================================
|  Archivo       : B_Maximum_Sum.cpp
|  Autor         : Russell
|  Fecha         : 2025-06-15 18:04
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Maximum Subarray Sum
|  - greedy
|  - *1100
==========================================================
*/

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
using i64 = int64_t;

template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vll = vector<ll>;
#define pb push_back
#define mp make_pair

const ll INF = 1e18;
const int MOD = 1e9 + 7;

ll gcd(ll a,ll b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

void solve(){
    int n,k; cin>>n>>k;
    vector<int64_t> a(n);
    int64_t sumTotal = 0;
    for(int e = 0 ;e < n ; e++){
        cin>>a[e];
        sumTotal += a[e];
    }
    
    int64_t maxCurrent = 0;
    int64_t maxGlobal = 0;
    for(int e = 0 ; e < n; e++){
        maxCurrent = max(a[e], maxCurrent + a[e]);
        maxGlobal = max(maxGlobal, maxCurrent);
    }
    int64_t restanteTotal = sumTotal - maxGlobal;
    maxGlobal %= MOD;
    for(int k_i = 1;k_i <= k ; k_i++){
        maxGlobal = maxGlobal * 2 % MOD;
    }
    maxGlobal = (maxGlobal + restanteTotal) % MOD;
    if(maxGlobal < 0) maxGlobal += MOD;
    cout << maxGlobal << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t; cin>>t;
    while(t--) solve();
    return 0;
}