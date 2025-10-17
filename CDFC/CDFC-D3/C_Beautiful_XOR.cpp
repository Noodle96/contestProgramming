/*
==========================================================
|  Archivo       : C_Beautiful_XOR.cpp
|  Autor         : Russell
|  Fecha         : 2025-10-17 16:32
|--------------------------------------------------------
|  Tópicos utilizados:
|  - div3
|  - bitmask
|  - constructive algorithms
==========================================================
*/

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;

using ll = long long;
using i64 = int64_t;
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

/* Caso General:
    a = 12, b = 6
    a=12          => 1100
    hidden=3      => 0011      <- Incognita 1
    tope=15       => 1111

    tope        => 1111
    hidden2=9   => 1001      <- Incognita 2
    b = 6       => 0110

*/ 

void solve(){
    i64 a,b; cin >> a >> b;
    if(a == b){
        cout << 0 << endl;
        return;
    }
    // Contamos los bits de a y b with libraries
    int bits_a  = bitlen_unsigned(a);
    int bits_b  = bitlen_unsigned(b);
    if(bits_a < bits_b){
        cout << -1 << endl;
        return;
    }
    // a es estrictamente mayor a b
    // a > b, entonces queremos encontrar hidden que es ls bits onvertidos de a
    i64 hidden = 0;
    int i = 0;
    // Recorremos los bits de a
    i64 a_ = a;
    while(a > 0){
        int last_bit_a_opuesto = (a & 1) ? 0 : 1;
        // cout << "last_bit_a_opuesto: " << last_bit_a_opuesto << endl;
        //         [0,1]      *  2^i

        hidden += (last_bit_a_opuesto * (1LL << i));
        a >>= 1; // dividimos a entre 2
        i++;
    }

    i64 tope = a_ ^hidden;
    i64 hidden2 = tope ^ b;
    
    cout << 2 << endl;
    cout << hidden << " " << hidden2 << endl;
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