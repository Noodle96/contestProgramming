/*
==========================================================
|  Archivo       : A_NP_Hard_Problem.cpp
|  Autor         : Russell
|  Fecha         : 2025-05-05 18:01
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Graphs
|  - BFS: bipartite check
|  - *1500
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
enum Color{ BLACK = 0, RED = 1, WHITE = 2};
vector<vector<int>> adj;
vector<Color> color;
vector<bool> isVisited;
bool isBipartite;

void bipartiteCheck(int s){
    isVisited[s] = true;
    color[s] = BLACK;
    queue<int> q;
    q.push(s);
    isBipartite = true;
    while(!q.empty() && isBipartite){
        int u = q.front();  q.pop();
        for(auto v: adj[u]){
            if(color[v] == WHITE){
                color[v] = Color(1-color[u]);
                q.push(v);
                isVisited[v] = true;
            }else if(color[v] == color[u]){
                isBipartite = false;
                isVisited[v] = true;
                break;
            }
        }
    }
}

void solve(){
    int n,m; cin>>n>>m;
    adj.assign(n,vector<int>());
    isVisited.assign(n,false);
    color.assign(n,WHITE);
    while(m--){
        int u,v;
        cin>>u>>v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int e = 0 ; e < n; e++){
        if(!isVisited[e]){
            bipartiteCheck(e);
            if(!isBipartite) break;
        }
        
    }
    // cout << "isBipartite: " << isBipartite << endl;
    if(!isBipartite){
        cout<<-1<<endl;
        return;
    }else{
        set<int> red, black;
        for(int e = 0 ; e < color.size(); e++){
            if(color[e] == BLACK) black.insert(e);
            else if(color[e] == RED) red.insert(e);
        }
        cout << black.size() << endl;
        for(auto e: black){
            cout << e+1 << " ";
        }cout << endl;
        cout << red.size() << endl;
        for(auto e: red){
            cout << e+1 << " ";
        }cout << endl;
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