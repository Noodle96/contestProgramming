/*
==========================================================
|  Archivo       : C_Spring.cpp
|  Autor         : Russell
==========================================================
*/

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;
using i64 = int64_t;
using i32 = int32_t;
using i128 = __int128_t;
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

ll lcm_ll(ll a, ll b) {
    return (ll)((i128)a / gcd(a, b) * b);
}
void solve() {
    ll a, b, c, m;
    cin >> a >> b >> c >> m;

    ll ac = lcm_ll(a, c);
    ll ab = lcm_ll(a, b);
    ll bc = lcm_ll(b, c);
    ll abc = lcm_ll(ab,c);
    ll cntA = m / a;
    ll cntB = m / b;
    ll cntC = m / c;
    ll cntAB = m / ab;
    ll cntAC = m / ac;
    ll cntBC = m / bc;
    ll cntABC = m / abc;
    ll onlyA = cntA - cntAB - cntAC + cntABC;
    ll onlyB = cntB - cntAB - cntBC + cntABC;
    ll onlyC = cntC - cntAC - cntBC + cntABC;
    ll onlyAB = cntAB - cntABC;
    ll onlyAC = cntAC - cntABC;
    ll onlyBC = cntBC - cntABC;
    ll alice = 6LL * onlyA + 3LL * onlyAB + 3LL * onlyAC + 2LL * cntABC;
    ll bob = 6LL * onlyB + 3LL * onlyAB + 3LL * onlyBC + 2LL * cntABC;
    ll carol = 6LL * onlyC + 3LL * onlyAC + 3LL * onlyBC + 2LL * cntABC;

    cout << alice << " " << bob << " " << carol << "\n";
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