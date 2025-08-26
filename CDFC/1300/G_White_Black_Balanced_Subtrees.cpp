 /*
==========================================================
|  Archivo       : G_black_white_balanced_subtree.cpp
|  Autor         : Russell
|  Fecha         : 2025-08-24
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Graphs
|  - DFS: TopologicalSort
|  - Dynamic Programming
|  - *1300
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

enum State{ 
    UNVISITED,
    VISITING,
    VISITED
};
vector<vector<int>> adj;
vector<State> state;
vector<int> topological_order;


void dfs_topologicalSort(int u){
    state[u] = VISITED;
    for(int v: adj[u]){
        if(state[v] == UNVISITED){
            dfs_topologicalSort(v);
        }
    }
    topological_order.pb(u);
}

void solve(){
    int n;
    cin >> n;
    adj.assign(n, vector<int>());
    state.assign(n, UNVISITED);
    for(int e = 0; e < n - 1; e++){
        int a;
        cin >> a;
        a--;
        adj[a].pb(e+1);
    }
    string s;
    cin >> s;
    // Hacemos un topological sort
    for(int u = 0 ; u < n; u++){
        if(state[u] == UNVISITED){
            dfs_topologicalSort(u);
        }
    }
    reverse(all(topological_order));
    /*
    cout << "priny orden topologico" << endl;
    for( int e = 0; e < topological_order.size(); e++){
        cout << topological_order[e] << " ";
    }cout << endl;
    */
    // dp[i][0]: representa la cantidad de nodos negros del subtree que tiene como raíz i
    // dp[i][1]: representa la cantidad de nodos blancos del subtree que tiene como raíz i
    vector<vector<int>> dp(n, vector<int>(2,0));
    for(int e = n-1 ; e >= 0; e--){
        int u = topological_order[e];
        int idx = s[u] == 'W';
        dp[u][idx] ++;
        for(int v: adj[u]){
            dp[u][0] += dp[v][0];
            dp[u][1] += dp[v][1];
        }
    }
    int ans = 0;
    for( int e = 0; e < n; e++){
        //cout << e+1 << ":" << endl;
        //cout << dp[e][0] << "-" << dp[e][1] << endl;
        // verificamos que los nodos blancos y negros de dicho subtree sean iguales 
        if(dp[e][0] == dp[e][1]) ans++;
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
    cin >> t;
    while(t--) solve();
    return 0;
}