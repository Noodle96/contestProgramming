/*
==========================================================
|  Archivo       : C_Online_Courses_In_BSU.cpp
|  Autor         : Russell
|  Fecha         : 2026-03-08 11:17
|--------------------------------------------------------
|  Tópicos utilizados:
|  - dfs and similar: cycle check, topological order
|  - graphs
|  - implementation
|  - *special problem
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

enum Status{
    UNVISITED,
    VISITING,
    VISITED,
};

void solve() {
    int n, k;
    cin >> n >> k;
    set<int> mainCourses;
    vector<vector<int>> adj(n, vector<int>());
    vector<int> topologicalOrder;

    for(int i = 0; i < k; i++){
        int a;
        cin >> a;
        a--;
        mainCourses.insert(a);
    }
    for(int i = 0; i < n; i++){
        int total;
        cin >> total;
        for(int j = 0; j < total; j++){
            int node; cin >> node;
            node--;
            adj[i].push_back(node);
        }
    }

    // Setear todos los nodos como no visitado
    vector<Status> status(n, UNVISITED);
    bool hasCycle = false;
    auto dfs_cycleCheck = [&](auto&& self, int u) -> void {
        status[u] = VISITING;
        // cout << "ANalizando node: " << u + 1 << "\n";
        for(auto &v: adj[u]){
            if(status[v] == UNVISITED){
                self(self, v);
            }else if(status[v] == VISITING){
                hasCycle = true;
                return;
            }
        }
        status[u] = VISITED;
    };

    // tenemos que ver si es que existe un ciclo en la componente que
    // tiene como origen a  main course k_i
    // Si es asi, es imposible de pasar todos los cursos
    for(auto k_i: mainCourses){
        // status.assign(n, UNVISITED);
        // cout << "entrar in: " << k_i + 1 << "\n";
        hasCycle = false;
        dfs_cycleCheck(dfs_cycleCheck, k_i);
        if(hasCycle){
            cout << -1 << "\n";
            return;
        }
    }

    // Si pasamos por aqui, significa que no existe un ciclo en toda la
    // componente  para  pasar el curso k_i
    auto dfs_topologicalOrder = [&](auto&& self, int u) -> void{
        status[u] = VISITED;
        for(auto &v: adj[u]){
            if(status[v] == UNVISITED){
                self(self, v);
            }
        }
        topologicalOrder.push_back(u);
    };
    status.assign(n, UNVISITED);
    for(auto u: mainCourses){
        if(status[u] == UNVISITED){
            dfs_topologicalOrder(dfs_topologicalOrder, u);
        }
    }

    // Recorremos el orden  topologico
    cout << (int)topologicalOrder.size() << "\n";
    for(auto to: topologicalOrder){
        cout << to + 1 << " ";
    }cout << "\n";
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