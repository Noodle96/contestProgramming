/*
==========================================================
|  Archivo       : C_Rumor.cpp
|  Autor         : Russell
|  Fecha         : 2025-05-05 17:21
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Graphs
|  - DFS: components
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

vector<vector<int>> adj;
vector<bool> isVisited;
vector<int> currentComponent;
vector<ll> costos;

void dfs(int u){
    if(isVisited[u]) return;
    isVisited[u] = true;
    currentComponent.pb(u);
    for(auto v: adj[u]){
        if(!isVisited[v]){
            dfs(v);
        }
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    adj.assign(n, vector<int>());
    costos.assign(n, 0LL);
    isVisited.assign(n, false);
    for(int i = 0; i < n ;i++) cin>>costos[i];
    while(m--){
        int u,v;
        cin>>u>>v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ll ans = 0;
    for(int u = 0 ; u < n; u++){
        if(!isVisited[u]){
            currentComponent.clear();
            dfs(u);
            ll minimoCosto = INF;
            for(auto v: currentComponent){
                minimoCosto = min(minimoCosto, costos[v]);
            }
            ans += minimoCosto;
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