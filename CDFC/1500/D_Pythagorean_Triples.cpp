/*
==========================================================
|  Archivo       : D_Pythagorean_Triples.cpp
|  Autor         : Russell
|  Fecha         : 2026-04-06 19:05
|--------------------------------------------------------
|  Tópicos utilizados:
|  - binary search
|  - math number
|  - *1500
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
ll maximo = 1e9;
map<ll, ll> squares;
vector<ll> squares_vec;
void pre(){
    ll x = 3;
    while( (x*x + 1 ) / 2 <= maximo){
        squares[(x*x + 1)/ 2] = x;
        squares_vec.pb((x*x + 1) / 2);
        x += 2;
    }
    // cout << "print pre" << "\n";
    // for(auto it : squares_vec){
    //     cout << it << " ";
    // }
    // cout << "\n";

}

void solve() {
    int n; cin >> n;
    if(n <= 3){
        cout << 0 << "\n";
        return;
    }
    auto it = lower_bound(all(squares_vec), n);
    if(*it != n){
        it--;
    }
    // cout << "*it: " << *it << "\n";
    cout << squares[*it]/2 << "\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    pre();
    int t;
    cin >> t;
    // t = 1;
    while (t--) {
        solve();
    }
    return 0;
}