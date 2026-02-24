/*
==========================================================
|  Archivo       : B_Karen_and_Coffee.cpp
|  Autor         : Russell
|  Fecha         : 2026-02-24 12:43
|--------------------------------------------------------
|  Tópicos utilizados:
|  - data structures: Diference Array
|  - implementation
|  - *1400
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
const int N = 2e5 + 5;

void solve() {
    int n,k,q;
    cin >> n >> k >> q;
    vector<ll> diff(N+1,0);
    // Construimos Diff array para contar la cantidad de veces
    // que cada posición es cubierta por los rangos
    for(int i = 0;  i < n; i++){
        int l,r;
        cin >> l >> r;
        l--, r--;
        diff[l]++;
        diff[r+1]--;
    }

    // Reconstruir el array a partir del diff array
    vector<ll> reconstruction(N+1,0);
    reconstruction[0] = diff[0];
    for(int i = 1 ; i <= N; i++){
        reconstruction[i] = reconstruction[i-1] + diff[i];
    }

    // Construimos un prefix sum para contar la cantidad de posiciones que son
    // cubiertas al menos k veces
    vector<ll> prefix_k(N+1,0);
    for(int i = 1; i <=N; i++){
        prefix_k[i] = prefix_k[i-1] + (reconstruction[i-1] >= k ? 1 : 0);
    }

    for(int i = 0 ; i < q; i++){
        int l,r; cin >> l >> r;
        cout << prefix_k[r] - prefix_k[l-1] << endl;
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