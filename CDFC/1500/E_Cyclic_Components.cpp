/*
==========================================================
|  Archivo       : E_Cyclic_Components.cpp
|  Autor         : Russell
|  Fecha         : 2026-03-06 18:55
|--------------------------------------------------------
|  Tópicos utilizados:
|  - dfs and similar
|  - graphs
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
    vector<bool> isVisited(n, false);
    vector<int> component_idx;
    vector<int> in(n,0);
    vector<int> out(n, 0);

    auto dfs = [&](auto&& self, int u) -> void {
        isVisited[u] = true;
        component_idx.push_back(u);
        for(auto &v: adj[u]){
            if(!isVisited[v]){
                self(self, v);
            }
        }
    };

    for(int i = 0 ; i < m; i++){
        int a,b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        in[a]++; out[a]++;
        in[b]++; out[b]++;
    }

    int ans = 0;
    for(int i = 0 ; i < n; i++){
        if(!isVisited[i]){
            component_idx.clear();
            dfs(dfs, i);
            // para que sea un ciclo segun las restricciones del problema
            // in[i] y out[i] de cada nodo de la componete tiene que ser 2
            bool in_out_2 = true;
            for(auto nd: component_idx){
                // if(in[nd] == 2 && out[nd] == 2){
                //     ;
                // }else{
                //     in_out_2 = false;
                // }
                if (in[nd] != 2 || out[nd] != 2){
                    in_out_2 = false;
                }
            }
            ans += (in_out_2 ? 1 : 0);
        }
    }
    cout << ans << "\n";
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