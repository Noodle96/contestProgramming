/*
==========================================================
|  Archivo       : B_Mahmoud_and_Ehab_and_the_bipartiteness.cpp
|  Autor         : Russell
|  Fecha         : 2026-03-03 23:46
|--------------------------------------------------------
|  Tópicos utilizados:
|  - dfs and similar: bipartite check
|  - graphs
|  - trees
|  - *1300
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

enum Color{
    BLACK = 0,
    RED = 1,
    WHITE = 2,
};

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adjList(n, vector<int>());
    vector<Color> colors(n, WHITE);
    bool isBipartite = true;

    auto BFS = [&](int u) -> void {
        colors[u] = BLACK;
        queue<int> q;
        q.push(u);
        while(!q.empty() && isBipartite){
            int u = q.front();
            q.pop();
            for(auto &v: adjList[u]){
                if(colors[v] == WHITE){
                    colors[v] = Color(1 - colors[u]);
                    q.push(v);
                }else if(colors[v] == colors[u]){
                    isBipartite = false;
                    break;
                }
            }
        }
    };

    for(int i = 0 ; i < n - 1; i++){
        int a,b;
        cin >> a >> b;
        a--,b--;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    // El grafo esta garantizado que es bipoartito, solo
    // hacemos el recorrido BFS para asignar colores a los nodos
    BFS(0);

    // Hasta este momento todos los nodos estan pintados de B = 0 y R = 1
    int Blacks = 0;
    int reds = 0;
    for(int i = 0; i < n; i++){
        if(colors[i] == BLACK) Blacks++;
        else reds++;
    }
    
    // Para cada nodo Black debera haber aristas a todos los nodos red 
    ll ans = 0;
    for(int i = 0 ; i < n; i++){
        if(colors[i] == BLACK){
            int current_edges = adjList[i].size();
            int remaining = reds - current_edges;
            ans += remaining;
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