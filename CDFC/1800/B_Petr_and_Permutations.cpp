/*
==========================================================
|  Archivo       : B_Petr_and_Permutations.cpp
|  Autor         : Russell
|  Fecha         : 2026-09-07 16:17
|--------------------------------------------------------
|  Tópicos utilizados:
|  - data structures: bit
|  - training
|  - math
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

class Fenwick{
    private:
        int n;
        vector<ll> bit;
    public:
        Fenwick(int n): n(n), bit(n+1, 0){}
        void update(int idx, ll val){
            while(idx <= n){
                bit[idx] += val;
                idx += (idx & -idx);
            }
        }
        ll query(int idx){
            ll sum = 0;
            while(idx > 0){
                sum += bit[idx];
                idx -= (idx & -idx);
            }
            return sum;
        }
        ll query(int l, int r){
            return query(r)- query(l - 1);
        }
};

void solve() {
    int n; cin >> n;
    Fenwick ft(n);
    vector<ll> a(n);
    ll ic = 0;
    for(int i = 0 ; i < n; i++){
        cin >> a[i];
    }
    // Calculamos el numero de inversiones en el arreglo
    for(int i =  n - 1; i >= 0; i--){
        ic  += ft.query(a[i] - 1); // <
        ft.update(a[i], +1);
    }
    int swap_petr = 3*n;
    if((ic % 2) == (swap_petr % 2)){
        cout << "Petr\n";
    }else{
        cout << "Um_nik\n";
    }

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