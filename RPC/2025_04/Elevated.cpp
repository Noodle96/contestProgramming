/*
==========================================================
|  Archivo       : Elevated.cpp
|  Autor         : Russell
|  Fecha         : 2025-04-29 17:40
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Graph: BFS: Components, AnchoComponents, distanciaAlExtremo
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
int n,q;
vector<vector<int>> adj;
vector<bool> isVisited;
vector<int> distMaximas;
vector<int> anchoNodes;
int totalAnchoPerComponent = 0;

void dfs_components(int u, vector<int> &componentNodes){
    if(isVisited[u]) return;
    isVisited[u] = true;
    componentNodes.pb(u);
    for(auto v: adj[u]){
        if(!isVisited[v]){
            dfs_components(v, componentNodes);
        }
    }

}
pair<unordered_map<int,int>, int> BFS(int start){
    unordered_map<int,int> dist;
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    int farthest_node = start;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v: adj[u]){
            if(!dist.count(v)){
                dist[v] = dist[u] + 1;
                q.push(v);
                if(dist[v] > dist[farthest_node]){
                    farthest_node = v;
                }
            }
        }
    }
    return {dist, farthest_node};
}


void solve(){
    cin>>n>>q;
    adj.assign(n, vector<int>());
    isVisited.assign(n, false);
    distMaximas.assign(n, -1);
    anchoNodes.assign(n, -1);
    for(int e = 0 ; e < n-3; e++){
        int u,v; cin>>u>>v;
        u--;v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    /*
        Esta garantizado que hay 3 componentes exactas.
    */
   int totalComponent = 0;  
    for(int e = 0 ; e < n; e++){
        // Identificamos los nodos de el componente_i
        if(!isVisited[e]){
            // cout << "component: " << totalComponent++ << endl;
            vector<int> componentNodes;
            dfs_components(e, componentNodes);
            // for(auto node: componentNodes){
            //     cout << node << " ";
            // }cout << endl;

            // Identificamos el ancho de dicho componente y la distancia maxima del nodo_i
            // al cualquiera de los extremos.
            // 01: Identificar uno de los extremos "u" de dicho componente.
            // auto [anyVector,u] = BFS(componentNodes[0], componentNodes.size());
        
            auto [anyHash, u]   = BFS(componentNodes[0]);
            // 02: Partimos de el extremo "u" y buscamos el otro extremo "v"
            auto [dist_u, v] = BFS(u);
            // cout << "print dist_u" << endl;
            // for(auto d_i: dist_u){
            //     cout << "\t"<<d_i.first << " " << d_i.second << endl;
            // }cout << endl;

            // 03: Ya tenemos el ancho de dicho componente
            // podemos optimizar esto con un DSU
            int anchoComponent_i = dist_u[v];
            totalAnchoPerComponent += anchoComponent_i;
            for(auto node: componentNodes){
                anchoNodes[node] = anchoComponent_i;
            }

            // cout << "anchoComponent_i: " << anchoComponent_i << endl;
            // 04: Empezamos en v, para hallar el maximo entre dist_v_i y dist_u_i
            auto [dist_v, _] = BFS(v);
            // 05: Hallamos el maximo entre dist_v_i y dist_u_i
            for(int node: componentNodes){
                distMaximas[node] = max(dist_u[node], dist_v[node]);
            }
        }

    }
    while(q--){
        int u,v; cin>>u>>v;
        u--;v--;
        auto partialTotalAnchoPerComponent = totalAnchoPerComponent;
        partialTotalAnchoPerComponent -= anchoNodes[u];
        partialTotalAnchoPerComponent -= anchoNodes[v];
        partialTotalAnchoPerComponent += 1;
        // cout << "partialTotalAnchoPerComponent: " << partialTotalAnchoPerComponent << endl;
        int ans = distMaximas[u] + 1;
        ans  += distMaximas[v] + 1;
        ans += partialTotalAnchoPerComponent;
        // cout << "u: " << u << " v: " << v << endl;
        cout << ans << endl;
    }
    // cout << "print distancias maximas" << endl;
    // for(auto d_i: distMaximas){
    //     cout << d_i << " ";
    // }cout << endl;
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