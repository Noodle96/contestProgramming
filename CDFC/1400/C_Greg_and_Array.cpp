/*
==========================================================
|  Archivo       : C_Greg_and_Array.cpp
|  Autor         : Russell
|  Fecha         : 2026-02-23 17:02
|--------------------------------------------------------
|  Tópicos utilizados:
|  - data structure: diff array
|  - dp: prfi sum
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

void solve() {
    int n,m,k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for(auto &x: a) cin >> x;
    vector<tuple<int,int,ll>> operaciones(m);
    for(int i = 0; i < m; i++){
        int l,r;
        cin >> l >> r;
        l--,r--;
        ll d; cin >> d;
        operaciones[i] = {l,r,d};
    }
    vector<ll> diff_countOperation(m+1,0);
    // Consitruir diff array para obtener la frecuencia de cada operacion
    for(int i = 0; i < k; i++){
        int x,y;
        cin >> x >> y;
        x--,y--;
        diff_countOperation[x] += 1;;
        diff_countOperation[y+1]--;
    }
    // Recistruimos para obtener la frecuencia de cada operacion
    vector<ll> freq_operaciones(m+1,0);
    freq_operaciones[0] = diff_countOperation[0];
    for(int i = 1 ; i < m+1; i++){
        freq_operaciones[i] = freq_operaciones[i-1] +  diff_countOperation[i];
    }
    
    vector<ll> diff_variation(n+1,0);
    // Recorremos operaciones
    for(int i = 0; i < m; i++){
        auto [l,r,d] = operaciones[i];
        ll freq = freq_operaciones[i];
        diff_variation[l] += d*freq;
        diff_variation[r+1] -= d*freq;
    }
    // Reconstruimos para obtener la variacion total de cada elemento
    vector<ll> variation(n+1,0);
    variation[0] = diff_variation[0];
    for(int i = 1; i < n+1; i++){
        variation[i] = variation[i-1] + diff_variation[i];
    }
    for(int i = 0; i < n; i++){
        cout << a[i] + variation[i] << " ";
    }
    cout << "\n";
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