/*
==========================================================
|  Archivo       : E_Binary_Inversions.cpp
|  Autor         : Russell
|  Fecha         : 2026-02-14 17:20
|--------------------------------------------------------
|  Tópicos utilizados:
|  - prefix sum
|  - training
|  - *1100
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
    int n; cin >> n;
    vector<ll> a(n), b(n);
    for(int i = 0 ; i < n; i++){
        cin >> a[i];
        b[i] = a[i];
    }

    ll ans = 0;
    // Original prefixSum
    vector<ll> ps(n);
    ps[n-1] = (a[n-1] == 0 ? 1 : 0);
    for(int i = n-2; i >= 0; i--){
        ps[i] = ps[i+1] + (a[i] == 0 ? 1 : 0);
    }

    auto Zeros = [&](vector<ll> base) -> void{
        ll ans_ = 0;
        for(int i = 0 ; i < n; i++){
            if(base[i] == 1) ans_ += ps[i]; 
        }
        ans =  max(ans, ans_);
    };
    Zeros(a);
    // Put 1 in the first 0
    for(int i = 0 ; i < n; i++){
        if(a[i] == 0){
            a[i] = 1;
            break;
        }
    }
    ps.assign(n,0);
    ps[n - 1] = (a[n - 1] == 0 ? 1 : 0);
    for (int i = n - 2; i >= 0; i--)
    {
        ps[i] = ps[i + 1] + (a[i] == 0 ? 1 : 0);
    }
    Zeros(a);

    //Put 0 in the first(final->begin) 1
    for(int i = n-1; i >= 0; i--){
        if(b[i] == 1){
            b[i] = 0;
            break;
        }
    }
    ps.assign(n, 0);
    ps[n - 1] = (b[n - 1] == 0 ? 1 : 0);
    for (int i = n - 2; i >= 0; i--)
    {
        ps[i] = ps[i + 1] + (b[i] == 0 ? 1 : 0);
    }
    Zeros(b);
    cout << ans << endl;
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