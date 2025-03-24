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
int caso = 1;
string line;
enum Status{UNVISITED = -1, VISITED = 1};
vector<vector<int>> adj;
vector<vector<int>> adj_transpose;
vector<Status> status;
vector<int> TopologicalSort;
vector<int> temporalComponents;
vector<vector<int>> sccs;
vector<int> scc_id;

void Kosaraju(int u, int model){
    if(model == 2) temporalComponents.pb(u);
    status[u] = VISITED;
    vector<int> &neighbours = (model == 1 ) ? adj[u] : adj_transpose[u];
    for(auto v: neighbours){
        if(status[v] == UNVISITED){
            Kosaraju(v,model);
        }
    }
    if(model == 1) TopologicalSort.pb(u);
}

void solve(){
    int n,m;
    cin>>n>>m;
    adj.assign(n,vector<int>());
    adj_transpose.assign(n,vector<int>());
    scc_id.assign(n,-1);
    while(m--){
        int u,v;
        cin>>u>>v;
        u--;v--;
        adj[u].push_back(v);
        adj_transpose[v].pb(u);
    }
    cin.ignore();
    getline(cin,line);

    // Paso 1: Encontrar SCCs con Kosaraju
    TopologicalSort.clear();
    status.assign(n,UNVISITED);
    for(int u = 0 ; u < n; u++){
        if(status[u] == UNVISITED){
            Kosaraju(u,1);
        }
    }

    status.assign(n,UNVISITED);
    sccs.clear();
    int scc_count = 0;
    for(int u = n-1; u >= 0; u--){
        if(status[TopologicalSort[u]] == UNVISITED){
            temporalComponents.clear();
            Kosaraju(TopologicalSort[u],2);
            for(int v: temporalComponents) scc_id[v] = scc_count;
            sccs.push_back(temporalComponents);
            scc_count++;
        }
    }

    // 2.- Formar el grafo condensado (DAG de SCCs)
    vector<vector<int>> adj_scc(scc_count,vector<int>());
    vector<int> in_degree(scc_count,0);
    for(int u = 0; u < n;u++){
        for(auto v: adj[u]){
            if(scc_id[u] != scc_id[v]){
                auto it = find(all(adj_scc[scc_id[u]]),scc_id[v]);
                if(it == adj_scc[scc_id[u]].end()){ // not found
                    adj_scc[scc_id[u]].push_back(scc_id[v]);
                    in_degree[scc_id[v]]++;
                }
            }
        }
    }

    // 03.- Contar los SCCs que no tienen aristas de entrada
    int count = 0;
    for(int v = 0; v < scc_count; v++){
        if(in_degree[v] == 0) count++;
    }
    cout << "Case " << caso++ << ": "<<count << endl;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t; cin>>t;
    while(t--)solve();
    return 0;
}