/*
==========================================================
|  Archivo       : Hierarchy.cpp
|  Autor         : Russell
|  Fecha         : 2025-07-26 17:13
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Graphs
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

// Hasher para pair<int,int>
struct pair_hash {
    size_t operator()(pii const &p) const noexcept {
        // Mezcla simple: desplazamiento y XOR
        return (size_t(p.first) << 32) ^ size_t(p.second);
    }
};

void solve(){
    int N;
    cin >> N;

    vector<int> in_degree(N+1, 0);
    // guardamos pares (superior, subordinado)
    unordered_set<pii, pair_hash> edges;
    edges.reserve(N*2);

    // Leemos las N-1 aristas iniciales
    for (int i = 0; i < N-1; i++) {
        int p, e;
        cin >> p >> e;
        in_degree[e]++;
        edges.insert({p, e});
    }

    // Contamos ceros y excesos
    int zeros = 0, excess = 0;
    for (int i = 1; i <= N; i++) {
        if      (in_degree[i] == 0) zeros++;
        else if (in_degree[i] >  1) excess++;
    }

    auto is_hierarchy = [&]() {
        return (zeros == 1 && excess == 0);
    };

    // Estado inicial
    cout << (is_hierarchy() ? "DA\n" : "NE\n");

    int Q;
    cin >> Q;
    while (Q--) {
        int a, b;
        cin >> a >> b;

        // Determinar dirección actual
        bool a_to_b = edges.count({a,b});
        int from = a_to_b ? a : b;
        int to   = a_to_b ? b : a;

        // 1) Quitar from→to
        {
            int &d = in_degree[to];
            if      (d == 1) zeros++;       // 1→0
            else if (d == 2) excess--;      // 2→1
            d--;
        }
        edges.erase({from, to});

        // 2) Insertar to→from
        {
            int &d = in_degree[from];
            if      (d == 0) zeros--;       // 0→1
            else if (d == 1) excess++;      // 1→2
            d++;
        }
        edges.insert({to, from});

        // 3) Comprobar jerarquía
        cout << (is_hierarchy() ? "DA\n" : "NE\n");
    }

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