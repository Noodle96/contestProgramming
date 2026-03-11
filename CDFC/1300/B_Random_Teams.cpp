/*
==========================================================
|  Archivo       : B_Random_Teams.cpp
|  Autor         : Russell
|  Fecha         : 2026-03-10 22:22
|--------------------------------------------------------
|  Tópicos utilizados:
|  - combinatorics
|  - constructive algorithms
|  - greedy
|  - math   
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

/*
    tenemos n personas y se tienen que formar m equipos
    Nos piden el maximo y minimo de saludos(amistades)
    Para el maximo:
        formamos m-1 equipos de una sola persona y el resto de x personas:
        T = (m-1)*1 + 1*x
        x = T - m + 1
        saludos, C(x,2) = x(x-1)/2 saludos
    Para el minimo dividimos en m equipos:
    Caso 1: m divide a n:
        personas_por_equipo = n/m
        total saludos sera:
            m * C(personas_por_equipo, 2)
    Caso 2: m no divide a n
        size = n / m
        r = n % m
        r equipos tendran  size + 1 personas
        m - r equipos tendran size personas
        personas_por_equipoA = size + 1
        personas_por_equipoB = size
        total = r * C(personas_por_equipoA,2) + (m-r) * C(personas_por_equipoB,2)
*/

void solve() {
    ll n,m;
    cin >> n >> m;

    auto Cn2 = [&](ll n) -> ll {
        return n * (n - 1) / 2;
    };

    // Para el maximo, hallamos el # personas que tendra dicho grupo
    ll x = n - m + 1;
    ll maximo_friends = Cn2(x);

    // P-ara el minimo
    ll minimo_friends;
    if(n%m == 0){
        ll personas_por_equipo = n/m;
        minimo_friends = m * Cn2(personas_por_equipo);
    }else{
        ll size = n / m;
        ll resto = n % m;
        ll personas_por_equipoA = size + 1;
        ll personas_por_equipoB = size;
        minimo_friends = resto * Cn2(personas_por_equipoA) + (m - resto) * Cn2(personas_por_equipoB); 
        
    }
    cout << minimo_friends << " " << maximo_friends << "\n";
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