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

vector<vector<int>> adj;
vector<bool> visited;
int totalVertices;
ll totalEdges;

void dfs(int e, bool isFirst){
    if(!isFirst) totalEdges++;
    if(visited[e]) return;
    visited[e] = true;
    totalVertices++;
    for(auto v : adj[e]){
        dfs(v,false);
    }
}

void solve(){
    int n, m;
    cin>>n>>m;
    adj.assign(n,vector<int>());
    visited.assign(n,false);
    while(m--){
        int a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector<pair<int,ll>> ansData;
    for(int e = 0 ; e < n; e++){
        if(!visited[e]){
            totalVertices = 0;
            totalEdges = 0;
            dfs(e,true);
            ansData.pb({totalVertices,totalEdges/2});
        }   
    }
    bool ans = true;
    for(auto [nodes,edges]: ansData){
        ll total = (ll)nodes*((ll)nodes-1)/2;
        ans &= ( total == (ll)edges);
    }
    cout << (ans ? "YES" : "NO") << "\n";

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