/*
==========================================================
|  Archivo       : G_Special Permutation.cpp
|  Autor         : Russell
|  Fecha         : 2026-02-07 16:08
|--------------------------------------------------------
|  Tópicos utilizados:
|  - constructive algorithm
|  - training
|  - *1600
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
    if(n <= 3){
        cout << -1 << endl;
        return;
    }
    if(n == 4){
        cout << "3 1 4 2" << endl;
        return;
    }
    vector<int> ans;
    if(n % 2 == 0){
        for(int i = 1;i <= n ; i+=2) ans.pb(i);
        ans.pb(n-4);
        for(int i = n; i >= 1; i-=2) if(i != n-4 )ans.pb(i);
    }else{
        for(int i = 1; i <=n; i+=2) ans.pb(i);
        ans.pb(n-3);
        for(int i = n-1; i >= 1; i-=2) if(i != n-3) ans.pb(i);
    }
    for(auto ans_i: ans){
        cout << ans_i << " ";
    }cout << endl;
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