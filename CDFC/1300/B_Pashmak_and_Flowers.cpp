/*
==========================================================
|  Archivo       : B_Pashmak_and_Flowers.cpp
|  Autor         : Russell
|  Fecha         : 2026-03-10 16:37
|--------------------------------------------------------
|  Tópicos utilizados:
|  - combinatorics
|  - implementation
|  - sorting
|  - *1300
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
    cin >> n;
    map<ll, ll> freq;
    vector<ll> a(n);
    for(int i = 0 ; i < n; i++){
        ll x; cin >> x;
        freq[x]++;
        a[i] = x;
    }
    sort(all(a));
    int mx = a[n-1];
    int mn = a[0];
    int maxDiference = mx - mn;
    ll ans;
    // SI todos los elementos son repetidos
    //ans = C(n,2) = n(n-1)/2
    if(freq.size() == 1){
        ans = n*(n-1)/2;
    }else{
        ans = freq[mx] * freq[mn];
    }
    cout << maxDiference << " " << ans << "\n";
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