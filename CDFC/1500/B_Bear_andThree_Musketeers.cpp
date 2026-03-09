/*
==========================================================
|  Archivo       : B_Bear_andThree_Musketeers.cpp
|  Autor         : Russell
|  Fecha         : 2026-03-08 16:34
|--------------------------------------------------------
|  Tópicos utilizados:
|  - dfs and similar:
|  - graphs
|  - brute force
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
    int n,m;
    cin >> n >> m;
    vector<set<int>> adj(n,set<int>());
    vector<bool> visited(n, false);
    vector<int> degree(n, 0);

    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        a--,b--;
        adj[a].insert(b);
        adj[b].insert(a);
        degree[a]++;
        degree[b]++;
    }

    auto existEdge = [&](int u, int v) -> bool {
        auto it = adj[u].find(v);
        if(it != adj[u].end()) return true;
        return false;
    };

    int ans = INF;
    auto dfs = [&](auto&& self, int u)-> void{
        visited[u] = true;
        vector<int> children;
        for(auto &v: adj[u]){
            children.pb(v);
        }
        int len_ch = children.size();
        for(int i = 0; i < len_ch; i++){
            for(int j = i+1; j < len_ch; j++){
                auto flag = existEdge(children[i],children[j]);
                if(flag){
                    int total = degree[u] + degree[children[i]] + degree[children[j]];
                    int remaining = total - 6;
                    ans = min(ans, remaining);
                }
            }
        }

        for (auto &v : adj[u]){
            if(!visited[v]){
                self(self, v);
            }
        }
    };

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(dfs, i);
        }
    }
    cout << (ans == INF ? -1 : ans) << "\n";
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