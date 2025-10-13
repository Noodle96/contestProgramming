/*
==========================================================
|  Archivo       : Judge.cpp
|  Autor         : Russell
|  Fecha         : 2025-10-11 14:07
|--------------------------------------------------------
|  Tópicos utilizados:
|  - rpc
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
    int n,m; cin >> n >> m;
   // diff[d] = cambios en el # de jueces ausentes en el día d
    vector<int> diff(m + 2, 0);
    for (int i = 0; i < n; i++) {
        int v; 
        cin >> v;
        for (int j = 0; j < v; j++) {
            int s, e; 
            cin >> s >> e; // intervalo [s, e] inclusive
            diff[s] += 1; // desde s hay 1 ausente más
            diff[e + 1] -= 1;// desde e+1 deja de estar ausente
        }
    }

    int ans = 0;
    int away = 0;// # de jueces ausentes acumulado por día

    for (int d = 1; d <= m; d++) {
        away += diff[d];
        int available = n - away;
        if (available >= 3) ans++;
    }
    cout << ans << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;
    //cin >> t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}