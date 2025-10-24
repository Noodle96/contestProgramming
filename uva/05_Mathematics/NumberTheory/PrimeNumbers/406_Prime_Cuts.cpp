/*
==========================================================
|  Archivo       : 406_Prime_Cuts.cpp
|  Autor         : Russell
|  Fecha         : 2025-10-24 17:21
|--------------------------------------------------------
|  Tópicos utilizados:
|  - prime numbers
|  - training
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
ll _sieve_size;
bitset<10000010> bs; // 1e7
vector<ll> p;
void preprocess(){
    auto sieve = [&](ll upperbound) {// range = [0..upperbound] 
        _sieve_size = upperbound+1;// to include upperbound => [0..upperbound]
        bs.set();// all 1s
        bs[0] = bs[1] = 0;  // except index 0+1
        for (ll i = 2; i < _sieve_size; ++i) if (bs[i]) {
            // cross out multiples of i starting from i*i
            for (ll j = i*i; j < _sieve_size; j += i)
                bs[j] = 0;
            p.push_back(i);// add prime i to the list
        }
    };
    sieve(10000000); // up to 10^7 (<1s)
}

void solve(i32 n, i32 c){
    vector<i64> primes;
    auto size = (int)p.size();
    primes.pb(1);
    for(int i = 0; i < size; i++){
        if(p[i] <= n) primes.pb(p[i]);
        else break;
    }
    int m = (int)primes.size();
    cout << n << " " << c << ":";
    if(m%2 == 0){
        if(c <= m/2){
            int take = 2 * c;
            int start = m/2 - c;
            for(int i = start; i < start + take; i++){
                cout << " " << primes[i];
            }cout << endl << endl;
        }else{
            // todo
            for(auto it: primes){
                cout << " " << it;
            }cout << endl << endl;
        }
    }else{
        if((c-1) <= m/2){
            int take = 2*c -1;
            int start = m/2 - (c -1);
            for(int i = start; i < start + take; i++){
                cout << " " << primes[i];
            }cout << endl << endl;
        }else{
             // todo
            for(auto it: primes){
                cout << " " << it;
            }cout << endl << endl;
        }
    }
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
    //cin >> t;
    t = 1;
    i32 a,b;
    while(cin >> a >> b){
        solve(a,b);
    }
    return 0;
}