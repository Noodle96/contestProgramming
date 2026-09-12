/*
==========================================================
|  Archivo       : B_Frog2.cpp
|  Autor         : Russell
|  Fecha         : 2026-09-11 19:13
|--------------------------------------------------------
|  Tópicos utilizados:
    Problema : B - Frog 2 (AtCoder Educational DP Contest)
    Link     : https://atcoder.jp/contests/dp/tasks/dp_b
    Topico(s): dp (programacion dinamica) - camino minimo en un DAG, dp 1D

    Idea (mismo grafo de Frog 1, con mas aristas por nodo):
    - Cada piedra i es un nodo.
    - Ahora cada nodo i tiene una flecha hacia i+1, i+2, ..., i+K (si existen),
        con peso |h[i]-h[j]|. Antes (Frog 1) K era fijo en 2.
    - dp[i] = costo minimo para llegar del nodo 0 al nodo i.
    - Sigue siendo un DAG con aristas solo "hacia adelante", asi que basta
        recorrer los nodos en orden creciente. La unica diferencia con
        Frog 1 es que ahora, para calcular dp[i], hay que mirar hasta K
        predecesores (i-1, i-2, ..., i-K) en vez de solo 2.
    - Complejidad: O(N*K) en vez de O(N).
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
    int n, k;
    cin >> n >> k;
    vector<ll> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    vector<ll> dp(n, INF);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        // predecesores de i: i-1, i-2, ..., i-K (los que existan, j>=0)
        for (int j = 1; j <= k; j++) {
            if (i - j < 0) break;
            dp[i] = min(dp[i], dp[i-j] + abs(h[i] - h[i-j]));
        }
    }
    cout << dp[n-1] << "\n";
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