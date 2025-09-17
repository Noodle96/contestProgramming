/*
==========================================================
|  Archivo       : C_Max_Tree.cpp
|  Autor         : Russell
|  Fecha         : 2025-09-17
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Dfs and similar: Orden Topologico
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

int n;
vector<vector<int>> adj;
vector<int> p, orderTopologico;
vector<bool> vis;

void dfs(int u) {
    vis[u] = true;
    for (int v : adj[u]){
        if (!vis[v]) dfs(v);
    }
    orderTopologico.push_back(u);
}

void solve(){
    cin >> n;
    adj.assign(n, vector<int>());
    p.assign(n, 0);
    vis.assign(n, false);
    orderTopologico.clear();
    orderTopologico.reserve(n);

    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        ll x, y; cin  >> x >> y;
        u--; v--;
        if (x >= y) {
            adj[v].push_back(u);
        } else {
            adj[u].push_back(v);
        }
    }

    for (int s = 0; s < n; ++s)
        if (!vis[s]) dfs(s);

    reverse(orderTopologico.begin(), orderTopologico.end());

    for (int i = 0; i < n; ++i)
        p[orderTopologico[i]] = i + 1;

    for (int i = 0; i < n; ++i) {
        if (i > 0) cout << " ";
        cout << p[i];
    }
    cout << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;
    cin >> t;
    // t = 1;
    while(t--){
        solve();
    }
    return 0;
}