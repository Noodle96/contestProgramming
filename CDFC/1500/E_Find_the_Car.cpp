/*
==========================================================
|  Archivo       : E_Find_the_Car.cpp
|  Autor         : Russell
|  Fecha         : 2026-04-08 15:01
|--------------------------------------------------------
|  Tópicos utilizados:
|  - binary search
|  - math
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

void solve() {
    ll n;
    int k, q;
    cin >> n >> k >> q;

    vector<ll> a, b;
    a.push_back(0);
    b.push_back(0);

    for(int i = 0; i < k; i++){
        ll x; cin >> x;
        a.push_back(x);
    }
    for(int i = 0; i < k; i++){
        ll x; cin >> x;
        b.push_back(x);
    }

    while(q--){
        ll x;
        cin >> x;

        auto it = lower_bound(all(a), x);
        int idx = it - a.begin();

        if(a[idx] == x){
            cout << b[idx] << " ";
        }else{
            ll dist_total = a[idx] - a[idx - 1];
            ll time_total = b[idx] - b[idx - 1];
            ll dist_parcial = x - a[idx - 1];

            ll ans = b[idx - 1] + (dist_parcial * time_total) / dist_total;
            cout << ans << " ";
        }
    }
    cout << "\n";
}
void solve2(){
    double a = 99999999;
    double b = 1;
    double c = a / b;
    cout << fixed << setprecision(0);
    cout << "c: " << c << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    // t = 1;
    while (t--) {
        solve();
    }
    return 0;
}