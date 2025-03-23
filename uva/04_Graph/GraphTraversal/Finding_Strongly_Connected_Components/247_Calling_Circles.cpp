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

vector<vector<int>> adj;
vector<vector<int>> adj_transpose;
vector<Status> status;
vector<int> TopologicalSort;
vector<string> temporalComponentNames;
int datasetNumber = 1;

int n,m, cont = 0;
map<string, int> map_names;
map<int, string> map_names_inverse;

void Kosaraju(int u, int model){
    if(model == 2) temporalComponentNames.pb(map_names_inverse[u]);
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
            cont = 0;
            adj.assign(n, vector<int>());
            adj_transpose.assign(n, vector<int>());
            while(m--){
                string name1, name2;
                cin>>name1>>name2;
                // cout << "debug inside " << endl;
                if(map_names.count(name1) == 0){
                    map_names[name1] = cont;
                    map_names_inverse[cont] = name1;
                    cont++;
                }
                if(map_names.count(name2) == 0){
                    map_names[name2] = cont;
                    map_names_inverse[cont] = name2;
                    cont++;
                }
                
                int u = map_names[name1];
                int v = map_names[name2];
                adj[u].pb(v);
                adj_transpose[v].pb(u);              
            }
            TopologicalSort.clear();
            status.assign(n,UNVISITED);
            for(int u = 0 ; u < n; u++){
                if(status[u] == UNVISITED){
                    Kosaraju(u, 1);
                }
            }
            status.assign(n,UNVISITED);
            vector<vector<string>> ans;
            for(int u = n-1; u >= 0; u--){
                if(status[TopologicalSort[u]] == UNVISITED){
                    temporalComponentNames.clear();
                    Kosaraju(TopologicalSort[u],2);
                    ans.pb(temporalComponentNames);
                }
            }
            if(datasetNumber != 1) cout << endl;
            cout << "Calling circles for data set " << datasetNumber++ << ":" << endl;
            for(int e = 0 ; e < ans.size(); e++){
                int j = 0;
                for(; j < ans[e].size()-1; j++){
                    cout << ans[e][j] << ", ";
                }
                cout << ans[e][j] << endl;
            }
            map_names.clear();
            map_names_inverse.clear();
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