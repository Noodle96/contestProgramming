/*
==========================================================
|  Archivo       : A_Frog1.cpp
|  Autor         : Russell
|  Fecha         : 2026-09-11 18:41
|--------------------------------------------------------
|  Tópicos utilizados:
    Problema : A - Frog 1 (AtCoder Educational DP Contest)
    Link     : https://atcoder.jp/contests/dp/tasks/dp_a
    Topico(s): dp (programacion dinamica) - camino minimo en un DAG, dp 1D

    Idea (el mismo grafo que dibujamos a mano):
    - Cada piedra i es un nodo.
    - Cada nodo i tiene una flecha hacia i+1 y otra hacia i+2 (si existen),
        con peso |h[i]-h[j]|.
    - dp[i] = costo minimo para llegar del nodo 0 al nodo i.
    - Como todas las flechas van hacia adelante (es un DAG), basta recorrer
        los nodos en orden creciente: cuando calculamos dp[i], dp[i-1] y
        dp[i-2] ya estan listos.
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
    int n;
    cin >> n;
    vector<ll> h(n);
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    vector<ll> dp(n, 0);
    dp[0] = 0;
    dp[1] = 0 + abs(h[1] - h[0]);
    for(int i = 2; i < n; i++){
        dp[i] = min(dp[i-2] + abs(h[i] - h[i-2]),
                    dp[i-1] + abs(h[i]-h[i-1]));
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