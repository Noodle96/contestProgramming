/*
==========================================================
|  Archivo       : A_Dorm_Water_Supply.cpp
|  Autor         : Russell
|  Fecha         : 2025-09-22 21:54
|--------------------------------------------------------
|  Tópicos utilizados:
|  - training
|  - dfs and similar: graph traversal
|  - graphs
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

const int INF = 1e9 +7;

ll gcd(ll a,ll b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
int n,p;
vector<vector<pii>> adj;
vector<bool> visited;
vector<int> indegree,outdegree;
int minimoPipe;
int outNode;


void dfs(int u){
    visited[u] = true;
    if(outdegree[u] == 0){
        outNode = u;
        return;
    }
    for(auto [v,c] : adj[u]){
        if(visited[v]) continue;
        minimoPipe = min(minimoPipe,c);
        dfs(v);
    }
}

void solve(){
    cin >> n >> p;
    adj.assign(n, vector<pii>());
    visited.assign(n, false);
    indegree.assign(n, 0);
    outdegree.assign(n, 0);
    while(p--){
        int u,v,c; cin >> u >> v >> c;
        u--;v--;
        adj[u].pb({v,c});
        outdegree[u]++;
        indegree[v]++;
    }
    vector<int> starts;
    for(int i = 0 ; i < n; i++)
        if(indegree[i] == 0) starts.pb(i);

    vector<tuple<int,int,int>> ans;
    for(auto s_i: starts){
        minimoPipe = INF;
        outNode = -1;
        dfs(s_i);
        if(outNode != -1 && minimoPipe != INF)
            ans.pb({s_i+1, outNode+1, minimoPipe});
    }
    sort(all(ans));
    cout << ans.size() << "\n";
    for(auto [a,b,c] : ans)
        cout << a << " " << b << " " << c << "\n";

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