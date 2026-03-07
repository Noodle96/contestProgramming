/*
==========================================================
|  Archivo       : B_Coach.cpp
|  Autor         : Russell
|  Fecha         : 2026-03-06 20:30
|--------------------------------------------------------
|  Tópicos utilizados:
|  - dfs and similar: # components
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
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>());
    vector<int> degree(n, 0);
    vector<bool> visited(n, false);
    vector<int> idx_component;
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
        degree[a]++;
        degree[b]++;
    }

    if(m == 0){
        for(int i = 0; i < n; i++){
            cout << i +1 << " ";
            if( (i + 1)% 3 == 0) cout << endl;
        }
        return;
    }

    auto dfs = [&](auto&& self, int u) -> void {
        visited[u] = true;
        idx_component.pb(u);
        for(auto v: adj[u]){
            if(!visited[v]){
                self(self, v);
            }
        }
    };

    int numComponent = 0;
    vector<vector<int>> groups;
    unordered_map<int, queue<vector<int>>> isolated_groups;
    bool flag = true;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            idx_component.clear();
            dfs(dfs, i);
            numComponent++;
            if(idx_component.size() > 3) flag = false;
            if(idx_component.size() == 3){
                groups.pb(idx_component);
            }else{ // group of 1 or 2
                int len = idx_component.size();
                isolated_groups[len].push(idx_component);
            }
        }
    }
    // Si hay un equipo con mas de 3 integrantes
    if(!flag){
        cout << -1 << "\n";
        return;
    }
    // Verificacion Temporal
    // verificar que cada nodo de cada componente tenga degree = 2.
    flag = true;
    for(auto component_i: groups){
        for(auto u: component_i){
            flag &= (degree[u] == 2);
        }
    }
    if(flag){
        // Cada nodo solitario pasa al grupo de 2
        if(isolated_groups[2].size() <= isolated_groups[1].size()){
            auto q2 = isolated_groups[2];
            auto q1 = isolated_groups[1];
            while(!q2.empty()){
                auto g2 = q2.front(); q2.pop();
                auto g1 = q1.front(); q1.pop();
                g2.push_back(g1[0]);
                groups.push_back(g2);
            }
            // Hasta el momento quedan k groups (k%3 == 0) de un solo nodo.
            while(!q1.empty()){
                auto a = q1.front(); q1.pop();
                auto b = q1.front(); q1.pop();
                auto c = q1.front(); q1.pop();
                a.push_back(b[0]);
                a.push_back(c[0]);
                groups.push_back(a);
            }
            for (auto component_i : groups){
                for (auto u : component_i){
                    cout << u + 1 << " ";
                }cout << "\n";
            }
        }else{
            cout << -1 << "\n";
        }
    }else{
        // Alguna componente de 3 falla
        cout << -1 << "\n";
    }
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