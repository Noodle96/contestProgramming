/*
==========================================================
|  Archivo       : B_Multiple_Construction.cpp
|  Autor         : Russell
|  Fecha         : 2025-09-20 10:16
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Implementation
|  - Div2
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
    int n; cin >> n;
    vector<int> ans;
    for(int e = n; e >= 1; e--){
        ans.pb(e);
    }
    ans.pb(n);
    for(int e = 1 ; e <= n-1; e++){
        ans.pb(e);
    }
    for(int e : ans){
        cout << e << " ";
    }cout << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;
    cin >> t;
    // t = 1;
    while(t--){
        solve();
    }
    return 0;
}