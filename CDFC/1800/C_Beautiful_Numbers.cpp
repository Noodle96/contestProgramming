/*
==========================================================
|  Archivo       : C_Beautiful_Numbers.cpp
|  Autor         : Russell
|  Fecha         : 2026-03-10 21:28
|--------------------------------------------------------
|  Tópicos utilizados:
|  - combinatorics
|  - brute force
|  - *1800
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

const ll MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;
ll fact[MAXN+1];
ll invfact[MAXN+1];

ll modpow(ll a, ll b){
    if(b == 0 ) return 1;
    ll half = modpow(a, b/2);
    ll res = (half * half) % MOD;
    if(b & 1){
        res = (res * a) % MOD;
    }
    return res;
}

void build(){
    fact[0] = 1;
    for(int i = 1; i <= MAXN; i++){
        fact[i] = i * fact[i-1] % MOD;
    }
    invfact[MAXN] = modpow(fact[MAXN], MOD - 2);
    for(int i = MAXN - 1; i >= 0; i--){
        invfact[i] = (i+1) * invfact[i+1] % MOD;
    }
}

ll C(int n, int k){
    if(k < 0 || k > n) return 0;
    return fact[n] * invfact[k] % MOD * invfact[n-k] % MOD;
}

void solve() {
    int a, b, n;
    cin >> a >> b >> n;

    // a = 6, b = 8
    // sum = 688886 true
    // sum = 688887 false
    auto is_good_number = [&](int sum) -> bool {
        if(sum == 0) return false;
        while(sum > 0){
            int d = sum % 10;
            if(d != a && d != b) return false;
            sum /= 10;
        }
        return true;
    };
    ll ans = 0;
    for(int i = 0; i <=n; i++){
        // seleccionamos el digito a (i veces),
        // por tanto el digito b (n-i) veces.
        int sum = i * a + (n-i)*b;
        /*
            si n = 4
            a = 2, b = 2
            de cuantas maneras selecciono a i elemento de
            un total de n?
                C(n,i)
                C(4,2) = 6
        */
        /*
            // sum tiene i=2 veces el a y (n-i)=2 veces el b.
            aabb
            abab
            abba
            baab
            baba
            bbaa
        */

        if(is_good_number(sum)){
            ans = (ans + C(n, i)) % MOD;
        }
    }
    cout << ans << "\n";


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    build();

    int t;
    // cin >> t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}