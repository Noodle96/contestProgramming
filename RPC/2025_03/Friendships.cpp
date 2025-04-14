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

vector<vector<int>> g;
vector<bool> isVisited;
ll nodeCount, edgesCount;

// count the number of nodes and edges in the graph
void countNodesAndEdges(int v, int &nodes, int &edges){
    if(isVisited[v]) return;
    isVisited[v] = true;
    nodes++;
    for(int u : g[v]){
        edges++;
        countNodesAndEdges(u, nodes, edges);
    }
}


void dfs(int v){
    if(isVisited[v]) return;
    isVisited[v] = true;
    nodeCount++;
    for(int u : g[v]){
        edgesCount++;
        dfs(u);
    }
}

ll ans = 0;

void solve(){
    int n,m;
    cin>>n>>m;
    g.assign(n, vector<int>());
    isVisited.assign(n, false);
    while(m--){
        int a,b;
        cin>>a>>b;
        a--;b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    for(int v = 0 ;v < n ; v++){
        if(!isVisited[v]){
            nodeCount = 0;
            edgesCount = 0;
            dfs(v);
            edgesCount /= 2; // each edge is counted twice
            // cout << nodeCount << " " << edgesCount << endl;
            ans += nodeCount*(nodeCount - 1)/2 - edgesCount;
        }
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
    solve();
    return 0;
}