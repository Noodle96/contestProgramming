/*
==========================================================
|  Archivo       : B_Alice_and_the_List_of_Presents.cpp
|  Autor         : Russell
|  Fecha         : 2026-03-10 15:20
|--------------------------------------------------------
|  Tópicos utilizados:
|  - combinatorics: binary exponentiation
|  - math
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

const ll MOD = 1e9 +7;

ll modpow(ll a, ll b){
    if(b == 0) return 1;
    ll half = modpow(a, b/2);
    ll res = half * half % MOD;
    if(b & 1){
        res = (res * a) % MOD;
    }
    return res;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    // cada regalo ira en alguna caja, que son los subconjuntos que se puede formar con m
    ll total_subconjuntos = modpow(2, m);
    // quitamos el subconjuto vacio {}
    total_subconjuntos--;
    
    // Luego el numero de manera de empaquetarlos de los n distintos regalos son
    // (2^m - 1) ^ n
    ll ans = modpow(total_subconjuntos, n);
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