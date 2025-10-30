/*
==========================================================
|  Archivo       : A_round_Trip.cpp
|  Autor         : Russell
|  Fecha         : 2025-10-30 13:59
|--------------------------------------------------------
|  Tópicos utilizados:
|  - div1+div2
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
// binary exponentiation recursivo
ll binaryExponentiation(ll base, ll exp){
    ll result = 1;
    while(exp > 0){
        if(exp % 2 == 1) // Si exp es impar
            result = result * base;
        base = base * base;
    exp = exp / 2;
    }
    return result;
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
    ll R, X, D;
    int n;
    cin >> R >> X >> D >> n;
    string s; cin >> s;

    auto update_R = [&](ll Rcur) -> ll {
        ll lo = max(0LL, Rcur - D);
        ll hi = Rcur + D;
        ll target = X - 1;
        if (target < 0) target = 0;
        if (target < lo) return lo;
        if (target > hi) return hi;
        return target;
    };

    int rated = 0;
    for (char c : s) {
        if (c == '1') {
            rated++;
            R = update_R(R);
        } else {
            if (R < X) {
                rated++;
                R = update_R(R);
            }
        }
    }
    cout << rated << endl;
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