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

enum Status{
    UNVISITED = -1,
    VISITED = 1,
};

int n,m;
vector<vector<int>> adj;
vector<vector<int>> adj_transpose;
vector<Status> status;
vector<int> TopologicalSort;

void Kosaraju(int u, int model){
    status[u] = VISITED;
    vector<int> &neighbours = (model == 1) ? adj[u] : adj_transpose[u];
    for(auto v: neighbours){
        if(status[v] == UNVISITED){
            Kosaraju(v, model);
        }
    }
    if(model == 1) TopologicalSort.pb(u);
}

void solve(){
    while(cin>>n>>m){
        if(n != 0 || m != 0){
            adj.assign(n,vector<int>());
            adj_transpose.assign(n,vector<int>());
            while(m--){
                int u,v,p;
                cin>>u>>v>>p;
                u--;v--;
                adj[u].pb(v);
                adj_transpose[v].pb(u);
                if(p == 2){
                    adj[v].pb(u);
                    adj_transpose[u].pb(v);
                }
            }
            TopologicalSort.clear();
            status.assign(n,UNVISITED);
            for(int u = 0 ; u < n; u++){
                if(status[u] == UNVISITED){
                    Kosaraju(u, 1);
                }
            }
            status.assign(n,UNVISITED);
            int numStronglyConnectedComponents = 0;
            for(int u = n-1; u >= 0; u--){
                if(status[TopologicalSort[u]] == UNVISITED){
                    Kosaraju(TopologicalSort[u], 2);
                    numStronglyConnectedComponents++;
                }
            }
            cout << (numStronglyConnectedComponents == 1 ? 1 : 0) << "\n";
        }
    }
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