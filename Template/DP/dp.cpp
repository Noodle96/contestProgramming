/*
==========================================================
|  Archivo       : dp.cpp
|  Autor         : Russell
|  Fecha         : 2026-09-09
|--------------------------------------------------------
|  Topicos utilizados:
|  - Programacion Dinamica (dp): memoizacion y tabulacion
|  - Knapsack (0/1, no acotado, subset-sum)
|  - LCS, LIS, LCIS (subsecuencias)
|  - Edit distance
|  - Interval DP
|  - Bitmask DP (TSP-like, conteo de ciclos)
|  - Digit DP
|  - Tree DP
|  - DP probabilistico / valor esperado
|  - Optimizacion Divide & Conquer sobre DP
|
|  Referencia rapida de problemas de Codeforces por patron
|  (todos verificados, con rating y link):
|   - 189A Cut Ribbon (1300)        -> knapsack no acotado
|   - 455A Boredom (1500)           -> dp 1D pick-or-skip
|   - 1195C Basketball Exercise(1400)-> dp alternando 2 filas
|   - 706C Hard problem (1600)      -> dp string con costo
|   - 1509C The Sports Festival(1800)-> interval dp
|   - 161D Distance in Tree (1800)  -> tree dp
|   - 148D Bag of mice (1800)       -> dp probabilistico
|   - 1036C Classy Numbers (1900)   -> digit dp
|   - 11D A Simple Task (2200)      -> bitmask dp (ciclos)
|   - 165E Compatible Numbers(2200) -> bitmask / SOS trick
|   - 55D Beautiful numbers (2500)  -> digit dp + lcm state
|   - 321E Ciel and Gondolas (2600) -> interval dp + D&C opt
|   - 10D LCIS (2800)               -> LCS + LIS combinados
|
|  Requiere C++17 (structured bindings, std::lcm).
|  Compilar:  g++ -std=c++17 -O2 dp.cpp -o dp
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
const ll LLINF = 4e18;

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

// ==========================================================
// SECCION 0: IDEA CENTRAL DE DP
// ==========================================================
// DP resuelve un problema descomponiendolo en subproblemas que se
// solapan (overlapping subproblems) y que tienen subestructura
// optima (optimal substructure): la solucion optima del problema
// grande se construye a partir de soluciones optimas de subproblemas.
//
// Dos formas de implementarlo:
//   1) Top-down (memoizacion): recursion normal + cache (mapa/array)
//      para no recalcular un mismo estado dos veces.
//   2) Bottom-up (tabulacion): se itera sobre los estados en un
//      orden tal que, al calcular dp[estado], sus dependencias
//      (subestados) ya esten calculadas.
//
// Para diseniar una dp siempre respondemos 3 preguntas:
//   - Estado: que informacion identifica un subproblema? (dp[i], dp[i][j], dp[mask], ...)
//   - Transicion: como paso de un estado a otro (o de sub-estados al estado actual)?
//   - Caso base: cual es el estado mas pequenio que ya conozco sin recursion?
//
// Complejidad tipica = (numero de estados) x (costo de cada transicion).

void seccion0_memo_vs_tab() {
    cout << "=== 0) Fibonacci: memoizacion vs tabulacion ===\n";

    // --- Top-down (memoizacion) ---
    vector<ll> memo(50, -1);
    function<ll(int)> fibMemo = [&](int n) -> ll {
        if (n < 2) return n;
        if (memo[n] != -1) return memo[n];
        return memo[n] = fibMemo(n-1) + fibMemo(n-2);
    };

    // --- Bottom-up (tabulacion) ---
    auto fibTab = [&](int n) -> ll {
        vector<ll> dp(n+2);
        dp[0] = 0; if (n >= 1) dp[1] = 1;
        for (int i = 2; i <= n; i++) dp[i] = dp[i-1] + dp[i-2];
        return dp[n];
    };

    cout << "fib(30) memo = " << fibMemo(30) << ", tab = " << fibTab(30) << "\n\n";
}

// ==========================================================
// SECCION 1: BASICO - DP 1D
// ==========================================================

// 1.1 Knapsack NO acotado (unbounded knapsack): maximizar piezas
// Estado: dp[n] = maximo numero de piezas usando longitud n
// Transicion: dp[n] = max(dp[n-a], dp[n-b], dp[n-c]) + 1
// CF 189A - Cut Ribbon (1300): https://codeforces.com/problemset/problem/189/A
int cutRibbon(int n, int a, int b, int c) {
    vector<int> dp(n+1, -INF);
    dp[0] = 0;
    for (int len = 1; len <= n; len++) {
        for (int piece : {a, b, c}) {
            if (len - piece >= 0 && dp[len-piece] != -INF) {
                dp[len] = max(dp[len], dp[len-piece] + 1);
            }
        }
    }
    return max(dp[n], 0);
}

// 1.2 DP 1D "tomar o saltar" (pick-or-skip), variante de House Robber.
// Al elegir un valor v, se eliminan TODAS las ocurrencias de v-1 y v+1.
// Truco: agrupamos por valor -> sum[v] = v * (cantidad de v en el arreglo).
// Asi el problema se vuelve: dp[v] = max(dp[v-1], dp[v-2] + sum[v]),
// exactamente como "House Robber" sobre el eje de valores.
// CF 455A - Boredom (1500): https://codeforces.com/problemset/problem/455/A
ll boredom(vector<int>& a) {
    int maxV = *max_element(all(a));
    vector<ll> sum(maxV + 1, 0);
    for (int x : a) sum[x] += x;

    vector<ll> dp(maxV + 1, 0);
    dp[0] = 0;
    if (maxV >= 1) dp[1] = sum[1];
    for (int v = 2; v <= maxV; v++) {
        dp[v] = max(dp[v-1], dp[v-2] + sum[v]);
    }
    return dp[maxV];
}

// 1.3 LIS (Longest Increasing Subsequence) - O(n^2), version pedagogica.
// (La version O(n log n) con patience sorting se deja como ejercicio de
// optimizacion; ver Template/DP/lis.cpp para ambas variantes: longitud
// y reconstruccion de la subsecuencia).
int lisN2(vector<int>& a) {
    int n = a.size();
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (a[i] > a[j]) dp[i] = max(dp[i], dp[j] + 1);
    return *max_element(all(dp));
}

void seccion1_basico() {
    cout << "=== 1) Basico: dp 1D ===\n";
    cout << "cutRibbon(5,5,3,2) = " << cutRibbon(5,5,3,2) << " (esperado 2)\n";
    cout << "cutRibbon(7,5,5,2) = " << cutRibbon(7,5,5,2) << " (esperado 2)\n";

    vector<int> a = {1, 2, 1, 3, 2, 2, 2, 2, 3};
    cout << "boredom({1,2,1,3,2,2,2,2,3}) = " << boredom(a) << " (esperado 10)\n";

    vector<int> lisArr = {8, 3, 4, 6, 5, 2, 0, 7, 9, 1};
    cout << "lisN2(...) = " << lisN2(lisArr) << " (esperado 4)\n\n";
}

// ==========================================================
// SECCION 2: INTERMEDIO
// ==========================================================

// 2.1 Knapsack 0/1 clasico: dp[i][w] = mejor valor usando los primeros i
// items con capacidad w. Transicion: no tomar item i, o tomarlo si cabe.
// Optimizable a 1D iterando w de mayor a menor.
int knapsack01(vector<int>& peso, vector<int>& valor, int W) {
    int n = peso.size();
    vector<int> dp(W + 1, 0); // dp[w] tras procesar items 0..i-1
    for (int i = 0; i < n; i++) {
        for (int w = W; w >= peso[i]; w--) {
            dp[w] = max(dp[w], dp[w - peso[i]] + valor[i]);
        }
    }
    return dp[W];
}

// 2.2 Subset sum: existe un subconjunto que sume exactamente S?
// dp[s] = true si es alcanzable. Es un caso particular de knapsack 0/1
// donde peso = valor y solo nos importa la factibilidad.
bool subsetSum(vector<int>& nums, int S) {
    vector<char> dp(S + 1, false);
    dp[0] = true;
    for (int x : nums) {
        for (int s = S; s >= x; s--) {
            if (dp[s - x]) dp[s] = true;
        }
    }
    return dp[S];
}

// 2.3 Coin change: numero MINIMO de monedas para formar S (no acotado).
// dp[s] = min(dp[s], dp[s-c] + 1) para cada moneda c.
int coinChangeMin(vector<int>& coins, int S) {
    vector<int> dp(S + 1, INF);
    dp[0] = 0;
    for (int s = 1; s <= S; s++) {
        for (int c : coins) {
            if (s - c >= 0 && dp[s-c] != INF) dp[s] = min(dp[s], dp[s-c] + 1);
        }
    }
    return dp[S] == INF ? -1 : dp[S];
}

// 2.4 Coin change: numero de FORMAS de dar cambio (orden no importa).
// Clave: iterar monedas en el loop EXTERNO evita contar permutaciones
// repetidas (cada combinacion se cuenta una sola vez).
ll coinChangeWays(vector<int>& coins, int S) {
    vector<ll> dp(S + 1, 0);
    dp[0] = 1;
    for (int c : coins) {
        for (int s = c; s <= S; s++) {
            dp[s] += dp[s - c];
        }
    }
    return dp[S];
}

// 2.5 LCS (Longest Common Subsequence).
// dp[i][j] = LCS de a[0..i) y b[0..j).
int lcs(string& a, string& b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dp[i][j] = (a[i-1] == b[j-1]) ? dp[i-1][j-1] + 1
                                          : max(dp[i-1][j], dp[i][j-1]);
    return dp[n][m];
}

// 2.6 Edit distance (Levenshtein): min operaciones (insertar/borrar/
// reemplazar) para convertir a en b.
int editDistance(string& a, string& b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
        }
    }
    return dp[n][m];
}

// 2.7 DP alternando entre dos filas (no se pueden elegir dos indices
// consecutivos de la MISMA fila). Estado dp[i][fila] = mejor suma
// usando el prefijo hasta i, terminando (o no) en esa fila.
// CF 1195C - Basketball Exercise (1400): https://codeforces.com/problemset/problem/1195/C
ll basketballExercise(vector<int>& h1, vector<int>& h2) {
    int n = h1.size();
    vector<array<ll,2>> dp(n, {0, 0});
    dp[0][0] = h1[0];
    dp[0][1] = h2[0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = max({(ll)h1[i], dp[i-1][0], dp[i-1][1] + h1[i]});
        dp[i][1] = max({(ll)h2[i], dp[i-1][1], dp[i-1][0] + h2[i]});
    }
    return max(dp[n-1][0], dp[n-1][1]);
}

// 2.8 Interval DP: minimizar suma de (max-min) al elegir el orden de
// insercion de un conjunto de valores.  Idea: si ordenamos el arreglo,
// el subconjunto optimo para un rango de "insercion" siempre corresponde
// a un intervalo CONTIGUO del arreglo ordenado. dp[l][r] = costo minimo
// de agregar el intervalo ordenado [l,r] en algun orden.
// CF 1509C - The Sports Festival (1800): https://codeforces.com/problemset/problem/1509/C
ll sportsFestival(vector<int> s) {
    sort(all(s));
    int n = s.size();
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    // dp[l][r] = costo minimo de ordenar optimamente s[l..r]
    for (int len = 2; len <= n; len++) {
        for (int l = 0; l + len - 1 < n; l++) {
            int r = l + len - 1;
            ll best = LLINF;
            ll range = s[r] - s[l];
            // el ultimo elemento insertado en [l,r] puede ser s[l] o s[r];
            // se prueban ambos extremos y se toma el mejor sub-intervalo restante.
            best = min(best, dp[l+1][r] + range);
            best = min(best, dp[l][r-1] + range);
            dp[l][r] = best;
        }
    }
    return dp[0][n-1];
}

// 2.9 DP de strings con costo (revertir o no cada string) para dejar
// el arreglo ordenado lexicograficamente con costo minimo.
// Estado: dp[i][0/1] = costo minimo considerando los primeros i strings,
// donde el string i quedo sin invertir (0) o invertido (1).
// CF 706C - Hard problem (1600): https://codeforces.com/problemset/problem/706/C
ll hardProblem(vector<string>& s, vector<ll>& cost) {
    int n = s.size();
    vector<string> rev = s;
    for (auto& x : rev) reverse(all(x));

    vector<array<ll,2>> dp(n, {LLINF, LLINF});
    dp[0][0] = 0;
    dp[0][1] = cost[0];
    for (int i = 1; i < n; i++) {
        for (int cur = 0; cur < 2; cur++) {
            string& curStr = cur == 0 ? s[i] : rev[i];
            for (int prev = 0; prev < 2; prev++) {
                if (dp[i-1][prev] == LLINF) continue;
                string& prevStr = prev == 0 ? s[i-1] : rev[i-1];
                if (prevStr <= curStr) {
                    ll c = dp[i-1][prev] + (cur == 1 ? cost[i] : 0);
                    dp[i][cur] = min(dp[i][cur], c);
                }
            }
        }
    }
    ll ans = min(dp[n-1][0], dp[n-1][1]);
    return ans == LLINF ? -1 : ans;
}

void seccion2_intermedio() {
    cout << "=== 2) Intermedio ===\n";

    vector<int> peso = {2, 3, 4, 5};
    vector<int> valor = {3, 4, 5, 6};
    cout << "knapsack01(W=5) = " << knapsack01(peso, valor, 5) << " (esperado 7)\n";

    vector<int> nums = {3, 34, 4, 12, 5, 2};
    cout << "subsetSum(sum=9) = " << (subsetSum(nums, 9) ? "true" : "false") << " (esperado true)\n";

    vector<int> coins = {1, 3, 4};
    cout << "coinChangeMin(S=6) = " << coinChangeMin(coins, 6) << " (esperado 2 = 3+3)\n";

    vector<int> coinsWays = {1, 2, 5};
    cout << "coinChangeWays(S=5) = " << coinChangeWays(coinsWays, 5) << " (esperado 4)\n";

    string a = "AGGTAB", b = "GXTXAYB";
    cout << "lcs(AGGTAB, GXTXAYB) = " << lcs(a, b) << " (esperado 4)\n";

    string s1 = "horse", s2 = "ros";
    cout << "editDistance(horse, ros) = " << editDistance(s1, s2) << " (esperado 3)\n";

    vector<int> h1 = {9,3,5,7,3}, h2 = {5,8,1,4,5};
    cout << "basketballExercise(...) = " << basketballExercise(h1, h2) << " (esperado 29)\n";

    vector<int> speeds = {3, 1, 2};
    cout << "sportsFestival({3,1,2}) = " << sportsFestival(speeds) << " (esperado 3)\n";

    vector<string> strs = {"ba", "ac"};
    vector<ll> costs = {1, 2};
    cout << "hardProblem({ba,ac}, {1,2}) = " << hardProblem(strs, costs) << " (esperado 1)\n\n";
}

// ==========================================================
// SECCION 3: AVANZADO
// ==========================================================

// 3.1 Bitmask DP: contar ciclos simples en un grafo (n <= ~20).
// Estado: dp[mask][v] = numero de caminos que usan exactamente el
// conjunto de vertices "mask", empiezan en el vertice mas bajo de mask
// y terminan en v. Al cerrar el ciclo (v conecta con el vertice mas
// bajo) se suma al total. Se divide por 2 al final porque cada ciclo
// se cuenta en ambos sentidos.
// CF 11D - A Simple Task (2200): https://codeforces.com/problemset/problem/11/D
ll countSimpleCycles(int n, vector<vector<int>>& adj) {
    vector<vector<ll>> dp(1 << n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++) dp[1 << i][i] = 1;

    ll totalCycles = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        int lowBit = __builtin_ctz(mask); // vertice mas bajo del conjunto
        for (int v = 0; v < n; v++) {
            if (dp[mask][v] == 0 || !(mask & (1 << v))) continue;
            for (int u : adj[v]) {
                if (u < lowBit) continue; // solo extendemos con vertices >= lowBit
                if (u == lowBit) {
                    // cerramos un ciclo, valido si tiene largo >= 3
                    if (__builtin_popcount(mask) >= 3) totalCycles += dp[mask][v];
                } else if (!(mask & (1 << u))) {
                    dp[mask | (1 << u)][u] += dp[mask][v];
                }
            }
        }
    }
    return totalCycles / 2;
}

// 3.2 Digit DP: contar numeros "classy" (a lo sumo 3 digitos != 0)
// en [1, N]. Estado: (posicion, cantidad de digitos no-cero usados,
// tight = si aun estamos acotados por N).
ll countClassyUpTo(ll N) {
    if (N <= 0) return 0;
    string s = to_string(N);
    int len = s.size();
    // memo[pos][cnt] con tight manejado por recursion (no se memoiza tight=true)
    vector<vector<ll>> memo(len + 1, vector<ll>(4, -1));

    function<ll(int,int,bool,bool)> rec = [&](int pos, int cnt, bool tight, bool started) -> ll {
        if (cnt > 3) return 0;
        if (pos == len) return started ? 1 : 0;
        if (!tight && memo[pos][cnt] != -1) return memo[pos][cnt];

        int limit = tight ? (s[pos] - '0') : 9;
        ll res = 0;
        for (int d = 0; d <= limit; d++) {
            bool nowStarted = started || d != 0;
            int nowCnt = cnt + ((d != 0) ? 1 : 0);
            res += rec(pos + 1, nowCnt, tight && (d == limit), nowStarted);
        }
        if (!tight) memo[pos][cnt] = res;
        return res;
    };
    return rec(0, 0, true, false);
}
ll countClassyInRange(ll L, ll R) {
    return countClassyUpTo(R) - countClassyUpTo(L - 1);
}
// CF 1036C - Classy Numbers (1900): https://codeforces.com/problemset/problem/1036/C

// 3.3 Digit DP avanzado: contar "beautiful numbers" en [1,N], es decir
// numeros divisibles por cada uno de sus digitos no-cero.
// Truco clave: en vez de guardar el numero exacto, guardamos el residuo
// modulo LCM(1..9) = 2520, y aparte que digitos no-cero han aparecido
// (bitmask de 9 bits) para poder calcular el lcm de los digitos usados
// al final. Esto acota el estado a (pos, residuo mod 2520, mascara de
// digitos usados) que es manejable.
// CF 55D - Beautiful numbers (2500): https://codeforces.com/problemset/problem/55/D
ll beautifulUpTo(ll N) {
    if (N <= 0) return 0;
    const int LCM_ALL = 2520; // lcm(1..9)
    string s = to_string(N);
    int len = s.size();
    // memo[pos][mod][mask]
    static map<tuple<int,int,int>, ll> memo;
    memo.clear();

    function<ll(int,int,int,bool,bool)> rec =
        [&](int pos, int mod, int mask, bool tight, bool started) -> ll {
        if (pos == len) {
            if (!started) return 0;
            int lcmDigits = 1;
            for (int d = 1; d <= 9; d++)
                if (mask & (1 << d)) lcmDigits = lcm(lcmDigits, d);
            return (mod % lcmDigits == 0) ? 1 : 0;
        }
        auto key = make_tuple(pos, mod, mask);
        if (!tight && started && memo.count(key)) return memo[key];

        int limit = tight ? (s[pos] - '0') : 9;
        ll res = 0;
        for (int d = 0; d <= limit; d++) {
            bool nowStarted = started || d != 0;
            int nowMod = (mod * 10 + d) % LCM_ALL;
            int nowMask = mask | (d != 0 ? (1 << d) : 0);
            res += rec(pos + 1, nowMod, nowMask, tight && d == limit, nowStarted);
        }
        if (!tight && started) memo[key] = res;
        return res;
    };
    return rec(0, 0, 0, true, false);
}
ll beautifulInRange(ll L, ll R) {
    return beautifulUpTo(R) - beautifulUpTo(L - 1);
}

// 3.4 Tree DP: contar pares de vertices a distancia exactamente k.
// Idea (dp por tamanios / "small to large" simplificado): al hacer DFS,
// cnt[v][d] = cantidad de vertices en el subarbol de v que estan a
// distancia d de v. Al visitar un hijo, ANTES de fusionar sus cuentas
// con las de v ya combinadas, se cuentan los pares cruzados que suman
// exactamente k, y luego se fusiona (truncando todo a distancia <= k,
// que es lo unico que puede importar).
// CF 161D - Distance in Tree (1800): https://codeforces.com/problemset/problem/161/D
ll distanceInTree(int n, int k, vector<vector<int>>& adj) {
    vector<vector<ll>> cnt(n); // cnt[v][d], acotado a distancias <= k
    ll answer = 0;

    function<void(int,int)> dfs = [&](int v, int parent) {
        cnt[v] = {1}; // distancia 0 = el propio v
        for (int u : adj[v]) {
            if (u == parent) continue;
            dfs(u, v);
            // contar pares cruzados: uno en cnt[v] a distancia "need" de v,
            // otro en cnt[u] a distancia d2 de u; la distancia total entre
            // ambos es need + (d2 + 1) [el +1 es la arista v-u], y queremos
            // que sea exactamente k.
            int limU = min((int)cnt[u].size(), k); // si d2+1 > k ya no sirve
            for (int d2 = 0; d2 < limU; d2++) {
                int need = k - (d2 + 1);
                if (need >= 0 && need < (int)cnt[v].size()) {
                    answer += cnt[v][need] * cnt[u][d2];
                }
            }
            // fusionar cnt[u] (desplazado +1 por la arista) dentro de cnt[v],
            // truncando a distancia k (mas alla de k no aporta nada).
            int newSize = min((int)cnt[u].size() + 1, k + 1);
            if (newSize > (int)cnt[v].size()) cnt[v].resize(newSize, 0);
            for (int d2 = 0; d2 + 1 < newSize; d2++) {
                cnt[v][d2 + 1] += cnt[u][d2];
            }
        }
    };
    dfs(0, -1);
    return answer;
}

// 3.5 DP probabilistico / valor esperado.
// Estado: dp[w][b] = probabilidad de que la PRINCESA (quien juega
// ahora) gane, con w ratones blancos y b negros en la bolsa.
// Transicion: se enumeran los 2 turnos (princesa saca, si no gana el
// dragon saca y luego un raton se escapa) para volver a un subestado
// mas chico dp[w'][b'].
// CF 148D - Bag of mice (1800): https://codeforces.com/problemset/problem/148/D
double bagOfMice(int w, int b) {
    vector<vector<double>> dp(w + 1, vector<double>(b + 1, 0.0));
    // Casos base: no quedan blancos -> princesa no puede ganar ya (0.0, valor por defecto)
    for (int bb = 0; bb <= b; bb++) dp[0][bb] = 0.0;

    for (int ww = 1; ww <= w; ww++) {
        for (int bb = 0; bb <= b; bb++) {
            int total = ww + bb;
            double p = (double)ww / total; // princesa saca blanco de inmediato
            if (bb >= 1) {
                // princesa saca negro (prob bb/total), luego dragon debe sacar
                // negro tambien para seguir en juego, y despues un raton se
                // escapa (puede ser blanco o negro) antes del turno siguiente.
                double pPrincesaNegra = (double)bb / total;
                double afterPrincesa_w = ww, afterPrincesa_b = bb - 1;
                if (afterPrincesa_b >= 1) {
                    double pDragonNegro = afterPrincesa_b / (afterPrincesa_w + afterPrincesa_b);
                    double afterDragon_w = afterPrincesa_w, afterDragon_b = afterPrincesa_b - 1;
                    double totalAfterDragon = afterDragon_w + afterDragon_b;
                    if (totalAfterDragon > 0) {
                        // un raton se escapa: blanco con prob w/total, negro con prob b/total
                        if (afterDragon_w >= 1) {
                            double pEscapeBlanco = afterDragon_w / totalAfterDragon;
                            p += pPrincesaNegra * pDragonNegro * pEscapeBlanco
                                 * dp[(int)afterDragon_w - 1][(int)afterDragon_b];
                        }
                        if (afterDragon_b >= 1) {
                            double pEscapeNegro = afterDragon_b / totalAfterDragon;
                            p += pPrincesaNegra * pDragonNegro * pEscapeNegro
                                 * dp[(int)afterDragon_w][(int)afterDragon_b - 1];
                        }
                    }
                }
            }
            dp[ww][bb] = p;
        }
    }
    return dp[w][b];
}

// 3.6 LCIS: Longest Common Increasing Subsequence (combina LCS + LIS).
// dp[j] = longitud de la LCIS que termina usando a[i] == b[j], tras
// procesar a[0..i]. Se actualiza con un "best" que acumula el mejor
// dp[j'] para b[j'] < a[i] visto hasta el momento (truco de O(n*m)).
// CF 10D - LCIS (2800): https://codeforces.com/problemset/problem/10/D
int lcis(vector<int>& a, vector<int>& b) {
    int n = a.size(), m = b.size();
    vector<int> dp(m, 0);
    for (int i = 0; i < n; i++) {
        int best = 0;
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j]) dp[j] = max(dp[j], best + 1);
            if (b[j] < a[i]) best = max(best, dp[j]);
        }
    }
    return *max_element(all(dp));
}

// 3.7 Bitmask trick tipo "SOS" (sum over subsets): para cada numero,
// encontrar otro del arreglo cuyo AND bit a bit sea 0 (compatibles).
// Idea: precomputar, para cada mascara, si ALGUN elemento del arreglo
// es submascara de ella (has[mask] = elemento presente que cabe en
// mask). Luego para buscar un compatible de x, basta mirar
// has[ (FULL_MASK) XOR x ], que es la maxima mascara compatible con x,
// propagada hacia abajo sobre sub-mascaras (esto es exactamente
// "sum over subsets" pero guardando un testigo en vez de una suma).
// CF 165E - Compatible Numbers (2200): https://codeforces.com/problemset/problem/165/E
vector<int> compatibleNumbers(vector<int>& a) {
    const int BITS = 22; // 4*10^6 < 2^22
    const int FULL = (1 << BITS) - 1;
    vector<int> has(1 << BITS, -1);
    for (int x : a) has[x] = x;

    for (int b = 0; b < BITS; b++) {
        for (int mask = 0; mask <= FULL; mask++) {
            if (!(mask & (1 << b)) && has[mask] == -1) {
                has[mask] = has[mask | (1 << b)];
            }
        }
    }
    vector<int> ans(a.size());
    for (int i = 0; i < (int)a.size(); i++) {
        ans[i] = has[FULL ^ a[i]];
    }
    return ans;
}

// 3.8 Interval DP + optimizacion Divide & Conquer sobre el argmin.
// Problema: particionar n elementos en k grupos contiguos minimizando
// la suma de costos internos de cada grupo (cost[l][r] precomputado).
// dp[grp][i] = costo minimo de partir los primeros i elementos en "grp"
// grupos contiguos. Transicion base (sin optimizar):
//   dp[grp][i] = min sobre j en [grp-1, i-1] de dp[grp-1][j] + cost[j][i-1]
// (el grupo numero "grp" ocupa los elementos [j, i-1], 0-indexado).
// Esa transicion es O(n) por estado -> O(k*n^2) total.
//
// Si cost cumple la "quadrangle inequality" (convexidad), el j optimo
// para cada i es monotono no decreciente en i, y podemos resolverlo con
// divide & conquer: al resolver dp[grp][mid], el j optimo esta entre el
// optimo de dp[grp][lo] y el de dp[grp][hi], lo que baja el costo total
// a O(k*n log n).
// CF 321E - Ciel and Gondolas (2600): https://codeforces.com/problemset/problem/321/E
ll gondolasIntervalDP(int n, int k, vector<vector<ll>>& cost /* cost[l][r], 0-indexed, inclusive */) {
    vector<vector<ll>> dp(k + 1, vector<ll>(n + 1, LLINF));
    dp[0][0] = 0;
    for (int grp = 1; grp <= k; grp++) {
        for (int i = grp; i <= n; i++) {
            for (int j = grp - 1; j <= i - 1; j++) {
                if (dp[grp-1][j] == LLINF) continue;
                dp[grp][i] = min(dp[grp][i], dp[grp-1][j] + cost[j][i-1]);
            }
        }
    }
    return dp[k][n];
}

ll gondolasDCOpt(int n, int k, vector<vector<ll>>& cost) {
    vector<vector<ll>> dp(k + 1, vector<ll>(n + 1, LLINF));
    dp[0][0] = 0;

    for (int grp = 1; grp <= k; grp++) {
        function<void(int,int,int,int)> solve = [&](int lo, int hi, int optLo, int optHi) {
            if (lo > hi) return;
            int mid = (lo + hi) / 2;
            ll best = LLINF;
            int bestOpt = optLo;
            // j debe cumplir j <= mid-1 (el grupo [j, mid-1] no puede ser vacio)
            for (int j = optLo; j <= min(mid - 1, optHi); j++) {
                if (dp[grp-1][j] == LLINF) continue;
                ll val = dp[grp-1][j] + cost[j][mid-1]; // grupo ocupa [j, mid-1]
                if (val < best) { best = val; bestOpt = j; }
            }
            dp[grp][mid] = best;
            solve(lo, mid - 1, optLo, bestOpt);
            solve(mid + 1, hi, bestOpt, optHi);
        };
        solve(grp, n, 0, n - 1);
    }
    return dp[k][n];
}

void seccion3_avanzado() {
    cout << "=== 3) Avanzado ===\n";

    // grafo K4 (clique de 4 vertices) -> 7 ciclos simples (4 triangulos + 3 de largo 4)
    vector<vector<int>> adj4(4);
    vector<pii> edges = {{0,1},{0,2},{0,3},{1,2},{1,3},{2,3}};
    for (auto [u,v] : edges) { adj4[u].pb(v); adj4[v].pb(u); }
    cout << "countSimpleCycles(K4) = " << countSimpleCycles(4, adj4) << " (esperado 7)\n";

    cout << "countClassyInRange(1,1000) = " << countClassyInRange(1, 1000) << " (esperado 1000)\n";
    cout << "countClassyInRange(999999,1000001) = " << countClassyInRange(999999, 1000001) << " (esperado 2)\n";

    cout << "beautifulInRange(1,9) = " << beautifulInRange(1, 9) << " (esperado 9)\n";
    cout << "beautifulInRange(12,15) = " << beautifulInRange(12, 15) << " (esperado 2)\n";

    // arbol: 1-2,2-3,3-4,2-5 (0-indexado: 0-1,1-2,2-3,1-4), k=2 -> 4 pares
    vector<vector<int>> tree(5);
    vector<pii> treeEdges = {{0,1},{1,2},{2,3},{1,4}};
    for (auto [u,v] : treeEdges) { tree[u].pb(v); tree[v].pb(u); }
    cout << "distanceInTree(k=2) = " << distanceInTree(5, 2, tree) << " (esperado 4)\n";

    printf("bagOfMice(1,3) = %.6f (esperado 0.500000)\n", bagOfMice(1, 3));
    printf("bagOfMice(5,5) = %.6f (esperado 0.658730)\n", bagOfMice(5, 5));

    vector<int> lcisA = {2, 3, 1, 6, 5, 4, 6};
    vector<int> lcisB = {1, 3, 5, 6};
    cout << "lcis(...) = " << lcis(lcisA, lcisB) << " (esperado 3)\n";

    vector<int> compat = {90, 36};
    auto comp = compatibleNumbers(compat);
    cout << "compatibleNumbers({90,36}) = {" << comp[0] << "," << comp[1] << "} (esperado {36,90})\n";

    // Particionar n=10 elementos en k=3 grupos contiguos minimizando la
    // suma de (largo del grupo)^2. Costo convexo -> el reparto optimo es
    // "lo mas parejo posible": tamanios 4,3,3 -> 16+9+9 = 34.
    int nG = 10, kG = 3;
    vector<vector<ll>> costG(nG, vector<ll>(nG, 0));
    for (int l = 0; l < nG; l++)
        for (int r = l; r < nG; r++)
            costG[l][r] = (ll)(r - l + 1) * (r - l + 1);
    ll bruteAns = gondolasIntervalDP(nG, kG, costG);
    ll dcAns = gondolasDCOpt(nG, kG, costG);
    cout << "gondolas: intervalDP=" << bruteAns << " dcOpt=" << dcAns << " (esperado ambos 34)\n";

    cout << "\n";
}

// ==========================================================
// MAIN
// ==========================================================
void solve() {
    seccion0_memo_vs_tab();
    seccion1_basico();
    seccion2_intermedio();
    seccion3_avanzado();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    startTime = clock();

    solve();

    return 0;
}
