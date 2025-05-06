/*
==========================================================
|  Archivo       : D_Substring.cpp
|  Autor         : Russell
|  Fecha         : 2025-05-05 19:34
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Graphs
|  - DFS: Cycle check
|  - Dynamic Programming
|  - *1700
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
bool hasCycle;

void dfs_checkedCycle(int u){
    state[u] = VISITING;
    for(int v: adj[u]){
        if(state[v] == UNVISITED){
            dfs_checkedCycle(v);
        }else if(state[v] == VISITING){
            hasCycle = true;
            return;
        }
    }
    state[u] = VISITED;
}

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
    int n,m;
    cin >> n >> m;
    adj.assign(n, vector<int>());
    state.assign(n, UNVISITED);
    string s;
    cin >> s;
    while(m--){
        int u,v;
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
    }
    // Verificamos si hay algun ciclo en el grafo dirigido
    for(int u = 0 ; u < n; u++){
        if(state[u] == UNVISITED){
            dfs_checkedCycle(u);
            if(hasCycle){
                cout << -1 << endl;
                return;
            }
        }
    }
    // Si no hay ciclos, podemos hacer un topological sort
    state.assign(n, UNVISITED);
    for(int u = 0 ; u < n; u++){
        if(state[u] == UNVISITED){
            dfs_topologicalSort(u);
        }
    }
    reverse(all(topological_order));

    // Ahora tenemos el orden topologico, ahora podemos hacer un dp
    // dp[u][alphabet]: Máximo número de veces que aparece el caracter alphabet en el camino hasta u
    vector<vector<int>> dp(n, vector<int>(26,0));
    int result = 0;
    for(int u: topological_order){
        int c = s[u] - 'a';
        dp[u][c]++;
        for(int v: adj[u]){
            for(int i = 0 ;i < 26 ; i++){
                dp[v][i] = max(dp[v][i], dp[u][i]);
            }
        }
        for(int e = 0 ; e < 26; e++){
            result = max(result, dp[u][e]);
        }
    }
    cout << result << endl;
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