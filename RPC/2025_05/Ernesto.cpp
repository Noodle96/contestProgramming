/*
==========================================================
|  Archivo       : Ernesto.cpp
|  Autor         : Russell
|  Fecha         : 2025-05-17 15:35
|--------------------------------------------------------
|  Tópicos utilizados:
|  - DFS: FloodFill
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
int casoP = 1;

unordered_map<string, int> names_id;
unordered_map<int, string> id_names;

vector<int> H;
vector<vector<int>> adj;
vector<bool> isVisited;
int currentId;
vector<int> currentComponent;

void dfs(int u){
    if(isVisited[u]) return;
    isVisited[u] = true;
    currentComponent.pb(u);
    for(auto v : adj[u]){
        if(!isVisited[v]){
            dfs(v);
        }
    }
}

void solve(){
    int n,m; cin>>n>>m;
    H.assign(n,0);
    adj.assign(n,vector<int>());
    isVisited.assign(n,false);
    names_id.clear();
    id_names.clear();
    H.clear();
    currentId = 0;

    for(int e = 0 ;e < n ; e++){
        string name; int h;
        cin>>name>>h;
        if(names_id.find(name) == names_id.end()){
            names_id[name] = currentId;
            id_names[currentId] = name;
            currentId++;
        }
        H[names_id[name]] = h;
    }
    while(m--){
        string name1, name2;
        cin>>name1>>name2;
        auto id1 = names_id[name1];
        auto id2 = names_id[name2];
        adj[id1].pb(id2);
        adj[id2].pb(id1);
    }
    set<string> ans;
    for(int e = 0 ;e < n ;e++){
        if(!isVisited[e]){
            currentComponent.clear();
            dfs(e);
            int maxH = 0;
            int idGanador =  -1;
            for(auto v : currentComponent){
                if(H[v] > maxH){
                    maxH = H[v];
                    idGanador = v;
                }
            }
            ans.insert(id_names[idGanador]);
        }
    }
    cout << "Case " << casoP++ << ":\n";
    for(auto name_i: ans){
        cout << name_i << "\n";
    }   
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t; cin>>t;
    while(t--) solve();
    return 0;
}