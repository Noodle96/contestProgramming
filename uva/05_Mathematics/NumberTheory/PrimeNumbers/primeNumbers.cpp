/*
==========================================================
|  Archivo       : primeNumbers.cpp
|  Autor         : Russell
|  Fecha         : 2025-10-24 15:58
|--------------------------------------------------------
|  Tópicos utilizados:
|  - training
|  - prime numbers
==========================================================
*/

/*
    Total primes found to 10000001(1e7 +1) : 664579(6e5)
    
    bool isPrime(ll N)
    // note: only guaranteed to work for N <= (last prime in vll p)^2
    the last prime in p is 9999991

    Criba de Eratóstenes:
        - Genera todos los números primos hasta un límite n en tiempo O(n log log n)
        - Utiliza un array booleano para marcar los números compuestos.
        - Itera desde 2 hasta √n, marcando los múltiplos de cada primo encontrado.

    Complejidad Temporal:
        O(nloglogn)

        Explicación:

        Para cada número primo p, se marcan sus múltiplos  2p, 3p, 4p, ⋯ ≤ n  como compuestos.
        Los múltiplos de p son n/p aproximadamente.
        Entonces el número total de operaciones es:
                        n(1/2 + 1/3 + 1/5 + 1/7 + …) = O(n log log n)
        (el término log log n viene de la suma armónica sobre los primos).
    
    Complejidad Espacial:
        O(n) para almacenar el array booleano.


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

// Naive Algorithm to check for prime number by definition: 
// divisible only by 1 and itself
// complejidad: O(sqrt(n))
bool isPrimeNaive(i32 n){
    if(n <= 1) return false;
    for(i32 i = 2; i*i <= n; i++){
        if(n % i == 0) return false;
    }
    return true;
}


ll _sieve_size;
bitset<10000010> bs; // 1e7
vector<ll> p;

void sieve(ll upperbound) {// range = [0..upperbound] 
    _sieve_size = upperbound+1;// to include upperbound => [0..upperbound]
    bs.set();// all 1s
    bs[0] = bs[1] = 0;  // except index 0+1
    for (ll i = 2; i < _sieve_size; ++i) if (bs[i]) {
        // cross out multiples of i starting from i*i
        for (ll j = i*i; j < _sieve_size; j += i)
            bs[j] = 0;
        p.push_back(i);// add prime i to the list
    }
}

bool isPrime(ll N) { // good enough prime test
    if (N < _sieve_size){
        cout << "[DEBUG] # menor a: " << _sieve_size << endl;
        return bs[N];
    }
    // O(1) for small primes
    cout << "[DEBUG] # mayor a _sieve_size: " << _sieve_size << "\n";
    for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
        if (N%p[i] == 0)
            return false;
    return true; // slow if N = large prime
} // note: only guaranteed to work for N <= (last prime in vll p)^2

void solve(){
    // inside int main()
    sieve(10000000); // up to 10^7 (<1s)
    //print all primes
    cout << "Total primes found to " << _sieve_size << " : " << (int)p.size() << "\n";
    for(auto pi: p){
        cout << pi << endl;
    }cout << endl;
    // cout << isPrime((1LL<<31)-1) << "\n";//2^31-1 is the 8th Mersenne prime
    // cout <<  isPrime(136117223861LL) << endl; // // 104729*1299709
    int a = 31;
    int b = 107;
    int c = 1e9 + 7;
    cout << "n: " << a << " is prime? " << (isPrime(a) ? "yes" : "no") << "\n";
    cout << "n: " << b << " is prime? " << (isPrime(b) ? "yes" : "no") << "\n";
    cout << "n: " << c << " is prime? " << (isPrime(c) ? "yes" : "no") << "\n";
}

void solve2(){
    i32 n; cin >> n;
    if(isPrimeNaive(n)){
        cout << n << " is a prime number.\n";
    } else {
        cout << n << " is not a prime number.\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;
    // cin >> t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}