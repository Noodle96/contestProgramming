/*
==========================================================
|  Archivo       : D_Yet_Another_Array_Problem.cpp
|  Autor         : Russell
|  Fecha         : 2025-10-29 17:01
|--------------------------------------------------------
|  Tópicos utilizados:
|  - div4
|  - brute force
|  - number theory
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
// El product de first_primes > 10^18 De es amanera garantizamos que algun a_i este dividido por algun primo en first_primes
ll first_primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};

void solve(){
    int n; cin >> n;
    vector<i64> a(n);
    for(auto &x : a) cin >> x;
    for(auto pi: first_primes){
        for(auto ai:a){
            if(ai % pi != 0){
                cout << pi << "\n";
                return;
            }
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
    int t;
    cin >> t;
    // t = 1;
    while(t--){
        solve();
    }
    return 0;
}