/*
==========================================================
|  Archivo       : B_Patchoulis_Magical_Talisman.cpp
|  Autor         : Russell
|  Fecha         : 2025-04-18 11:33
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Bitmask
|  - Constructive algorithms
|  - *800
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
    int n; cin>>n;
    array<vector<int>, 2> oddEven;
    for(int e = 0 ;e < n ; e++){
        int x; cin>>x;
        if(x & 1) oddEven[1].pb(x);
        else oddEven[0].pb(x);
    }
    // hay al menos un impar
    if(oddEven[1].size() > 0){
        cout << oddEven[0].size() << endl;
    }else{
        // todos son pares
        int trailingZeros = INT_MAX;
        for(int e = 0 ;e < oddEven[0].size() ; e++){
            trailingZeros = min(trailingZeros, __builtin_ctz(oddEven[0][e]));
        }
        // trailingZeros sera como minimo 1 ya que todos eran pares
        int ans = trailingZeros + (oddEven[0].size() - 1);
        cout << ans << endl;
    }
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