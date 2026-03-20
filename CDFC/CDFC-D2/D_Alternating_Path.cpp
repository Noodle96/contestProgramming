/*
==========================================================
|  Archivo       : D_Alternating_Path.cpp
|  Autor         : Russell
|--------------------------------------------------------
|  Tópicos utilizados:
|  - dfs and similar: check bipartite
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


enum Color {BLACK = 0, RED = 1, WHITE = 2};
struct ComponentInfo {
    bool isBipartite;
    int cnt0;
    int cnt1;
};
void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>());
    vector<Color> colors(n, WHITE);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto BFS_checkBipartite = [&](int start) -> ComponentInfo {
        queue<int> q;
        q.push(start);

        colors[start] = BLACK;

        int cnt0 = 1;
        int cnt1 = 0;
        bool isBipartite = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto v : adj[u]) {
                if (colors[v] == WHITE) {
                    colors[v] = Color(1 - colors[u]);

                    if (colors[v] == BLACK) {
                        cnt0++;
                    } else {
                        cnt1++;
                    }

                    q.push(v);
                } else if (colors[u] == colors[v]) {
                    isBipartite = false;
                }
            }
        }

        return {isBipartite, cnt0, cnt1};
    };
    
    ll answer = 0;
    for (int start = 0; start < n; start++) {
        if (colors[start] != WHITE) continue;

        ComponentInfo info = BFS_checkBipartite(start);

        if (info.isBipartite) {
            answer += max(info.cnt0, info.cnt1);
        }
    }

    cout << answer << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    // t = 1;
    while (t--) {
        solve();
    }
    return 0;
}