/*
==========================================================
|  Archivo       : 10852_Less_Prime.cpp
|  Autor         : Russell
|  Fecha         : 2025-10-24 18:11
|--------------------------------------------------------
|  Tópicos utilizados:
|  - number theory: primes with sieve of Eratosthenes
|  - training
|  - Lev 2
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

ll gcd(ll a,ll b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
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
int bitlen_unsigned(unsigned long long n){
    // __builtin_clzll: Cuenta los ceros a la izquierda
    return (n == 0) ? 1 : 64 - __builtin_clzll(n);
}

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}


/*
    Tenemos n in [100, 10000]
    find x, x<= n
    tal que  n - px sea maximo
    donde  px <=  n  < (p+1)x
    de aqui:
        px <=  n  < (p+1)x
        px <=  n  < px + x
        0 <= n - px < x 

        para p = 1:        para p = 2:
        0 <= n-x < x       0 <= n-2x < x
        0 <= n < 2x        0 <= n < 3x
             n/2 < x (1)        n/3 < x (2)
        
        Mientras p aumeta la parte iquierda de la ecuacion (1) se hace mas pequeño
        por lo tanto lo optimo es que sea p = 1
        entonces, comop esta ordenado hacemos una busqueda binaria para encontrar el 
        elemento mas mayor que n/2
*/


ll _sieve_size;
bitset<10000010> bs; // 1e7
vector<ll> p;
void sieve(ll upperbound) {
    _sieve_size = upperbound+1;// to include upperbound => [0..
    bs.set();// all 1s
    bs[0] = bs[1] = 0;  // except index
    for (ll i = 2; i < _sieve_size; ++i) if (bs[i]) {
        // cross out multiples of i starting from i*i
        for (ll j = i*i; j < _sieve_size; j += i)
            bs[j] = 0;
        p.push_back(i);// add prime i to the list
    }
}
void preprocess(){
    ll limite = 1e7;
    sieve(limite); // up to 10^7 (<1s)
}

void solve(){
    ll n; cin >> n;
    n /= 2;

    // el vector p(primos) ya esta ordenado, asi que hacemos una busqueda binaria
    // auto ub = upper_bound(all(p), n);
    // int index = (int)(ub - p.begin());
    // cout << p[index] << endl;
    // es por ello que hacemos busqueda binaria simulando upper_bound

    i32 left = 0;
    i32 right = (int)p.size() -1;
    i32 idx = -1;
    while(left <= right){
        i32 mid = left + (right - left)/2;
        if(p[mid] <= n){
            idx = mid;
            left = mid + 1;
        }else{
            right = mid -1;
        }
    }
    cout << p[idx+1] << endl;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    preprocess();
    int t;
    cin >> t;
    // t = 1;
    while(t--){
        solve();
    }
    return 0;
}