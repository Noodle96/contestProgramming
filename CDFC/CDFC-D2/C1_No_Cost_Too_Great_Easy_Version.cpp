/*
==========================================================
|  Archivo       : C1_No_Cost_Too_Great_Easy_Version.cpp
|  Autor         : Russell
|  Fecha         : 2025-10-19 18:16
|--------------------------------------------------------
|  Tópicos utilizados:
|  - div2
|  - train
|  - nnumber theory
|  - implementation
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

void solve(){
    int n; cin >> n;
    vector<i32> a(n);
    i32 evenCount = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] % 2 == 0) evenCount++;
    }
    sort(all(a));
    vector<i32> b(n);
    for(int i = 0 ; i < n; i++)
        cin >> b[i];
    
    if(evenCount >= 2){
        cout << 0 << endl;
        return;
    }

    auto primeFactors = [](i32 x) {
        vector<i32> factors;
        for (i32 i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                factors.pb(i);
                while (x % i == 0) {
                    x /= i;
                }
            }
        }
        if (x > 1) {
            factors.pb(x);
        }
        return factors;
    };

    unordered_map<i32, i32> primeFactorCount;
    auto addPrimeFactor = [&](i32 prime) {
        primeFactorCount[prime]++;
    };
    auto deletePrimeFactor = [&](i32 prime) {
        primeFactorCount[prime]--;
        if (primeFactorCount[prime] == 0) {
            primeFactorCount.erase(prime);
        }
    };


    // Descomponemos cada numero en factores primos y lo guardamos en un hash
    for(auto val_i: a){
        auto factors = primeFactors(val_i);
        for(auto f: factors){
            addPrimeFactor(f);
        }
    }

    //Verificamos que si se puede simplificar algun par de numeros iterativamente
    for(auto val_i: a){
        auto factors = primeFactors(val_i);
        for(auto f: factors)
            deletePrimeFactor(f);
        
        for(auto f:factors){
            if(primeFactorCount.find(f) != primeFactorCount.end()){
                cout << 0 << endl;
                return;
            }
        }

        for(auto f: factors)
            addPrimeFactor(f);
    }

    //Ahora verificamos si se puede simplificar algun par de numeros sumando uno
    // a alguno de ellos.
    for(auto val_i: a){
        auto factors = primeFactors(val_i);
        auto factors_plus_one = primeFactors(val_i + 1);
        for(auto f: factors)
            deletePrimeFactor(f);
        for(auto f:factors_plus_one){
            if(primeFactorCount.find(f) != primeFactorCount.end()){
                cout << 1 << endl;
                return;
            }
        }
        for(auto f: factors)
            addPrimeFactor(f);
    }
    // Finalmente se sacaria 2
    cout << 2 << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;
    cin >> t;
    // t = 1;
    while(t--){
        solve();
    }
    return 0;
}