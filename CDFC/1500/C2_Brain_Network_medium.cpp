/*
==========================================================
|  Archivo       : C2_Brain_Network_medium.cpp
|  Autor         : Russell
|  Fecha         : 2026-03-06 23:42
|--------------------------------------------------------
|  Tópicos utilizados:
|  - dfs and similar: diameter of tree
|  - graphs
|  - trees
|  - *1500
==========================================================
*/

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;
using i64 = int64_t;
using i32 = int32_t;
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

const int INF = 1e9;

ll gcd(ll a, ll b) {
    if (a % b == 0) return b;
    else return gcd(b, a % b);
}

ll floordiv(ll a, ll b) {
    if (a >= 0) return a / b;
    return - ( (-a + b - 1) / b );
}

ll ceildiv(ll a, ll b) {
    // ceil(a/b) = -floor((-a)/b)
    if (a >= 0) return (a + b - 1) / b;
    return - ( (-a) / b );
}

int bitlen_unsigned(unsigned long long n) {
    // __builtin_clzll: Cuenta los ceros a la izquierda
    return (n == 0) ? 1 : 64 - __builtin_clzll(n);
}

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>());
    vector<int> dist(n, -1);
    auto bfs = [&](int start) -> pair<int,int>{
        dist[start] = 0;
        int farthest = start;
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            auto u = q.front();
            q.pop();
            for(auto v: adj[u]){
                if(dist[v] == -1){
                    dist[v] = dist[u] + 1;
                    q.push(v);
                    if(dist[v] > dist[farthest]){
                        farthest = v;
                    }
                }
            }

        }
        // cout << farthest << " " << dist[farthest] << endl;
        return {farthest, dist[farthest]};
    };

    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    auto [node_farthest1, distancia_farthest1] = bfs(0);
    dist.assign(n, -1);
    auto [node_farthest2, diameter] = bfs(node_farthest1);
    cout << diameter << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;
    // cin >> t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}