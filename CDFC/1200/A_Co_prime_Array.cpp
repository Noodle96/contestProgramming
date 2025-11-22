/*
==========================================================
|  Archivo       : A_Co_prime_Array.cpp
|  Autor         : Russell
|  Fecha         : 2025-11-21 17:46
|--------------------------------------------------------
|  Tópicos utilizados:
|  - number theory
|  - training
|  - *1200
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

ll _sieve_size;
bitset<10000010> bs;
vector<ll> primes;
void sieve(ll upperbound) {
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
        for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
        primes.push_back(i);
    }
}

void solve() {
    sieve(10000000);
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    set<ll> factores_primos_temp;

    // La complajidad de la función es O(sqrt(n)) en el peor caso
    // ll x <= 10^9 entonces sqrt(x) <= 31622 aprox 3e4
    auto factores_primos = [&](ll x){
        for(auto i = 2; i * i <= x; i++) {
            while(x % i == 0) {
                factores_primos_temp.insert(i);
                x /= i;
            }
        }
        if(x > 1)
            factores_primos_temp.insert(x);
    };
    vector<ll> ans;
    for(int i = 0 ; i + 1 < n ; i++) {
        if(gcd(a[i], a[i+1]) != 1){
            factores_primos_temp.clear();
            factores_primos(a[i]);
            factores_primos(a[i + 1]);
            ans.push_back(a[i]);
            ll candidato = 0;
            for(auto prime: primes){
                if(factores_primos_temp.find(prime) == factores_primos_temp.end()){
                    candidato = prime;
                    ans.push_back(candidato);
                    break;
                }
            }
        }else{
            ans.push_back(a[i]);
        }
    }
    ans.push_back(a[n - 1]);
    cout << (int)ans.size() - n << endl;
    for(auto x: ans){
        cout << x << " ";
    }cout << endl;
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