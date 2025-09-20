/*
==========================================================
|  Archivo       : B_Mr_Kitayutas_Colorful_Graph.cpp
|  Autor         : Russell
|  Fecha         : 2025-09-19 18:13
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Dfs and similar
|  - Graphs
|  - dp
|  - Training
|  - *1400
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
int n, m;
vector<vector<pii>> adj; // (node, color)
vector<bool> visited;

bool dfs(int start, int final, int color){
    visited[start] = true;
    if(start == final) return true;
    for(auto [v, c]: adj[start]){
        if(!visited[v] && c == color){
            if(dfs(v, final, color)) return true;
        }
    }
    return false;
}

void solve(){
    cin >> n >> m;
    adj.assign(n, vector<pii>());
    visited.assign(n, false);
    for(int i = 0 ;i < m ; i++){
        int u, v, c;
        cin >> u >> v >> c;
        u--; v--;
        adj[u].pb(mp(v, c));
        adj[v].pb(mp(u, c));
    }
    int q; cin >> q;
    while(q--){
        int u, v; cin >> u >> v;
        u--; v--;
        int ans  = 0;
        for(int color = 1; color <= 100; color++){
            visited.assign(n, false);
            if(dfs(u,v,color)) ans++;
        }
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
    int t;
    //cin >> t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}