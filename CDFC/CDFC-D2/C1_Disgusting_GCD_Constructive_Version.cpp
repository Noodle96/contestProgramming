/*
==========================================================
|  Archivo       : C1_Disgusting_GCD_Constructive_Version.cpp
|  Autor         : Russell
|  Fecha         : 2026-11-06
|--------------------------------------------------------
|  Tópicos utilizados:
|  - div2
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

const int LIM = 2e5;
vector<int> nextP;

void buildSieve() {
    vector<bool> isComposite(LIM + 1, false);
    isComposite[0] = isComposite[1] = true;
    for (int i = 2; (ll)i * i <= LIM; i++)
        if (!isComposite[i])
            for (int j = i * i; j <= LIM; j += i)
                isComposite[j] = true;

    nextP.assign(LIM + 1, 0);
    nextP[LIM] = LIM;
    for (int x = LIM - 1; x >= 0; x--)
        nextP[x] = isComposite[x + 1] ? nextP[x + 1] : (x + 1);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;

    for (int i = 0; i < n; i++) {
        int p = nextP[a[i]];
        cout << p << " ";
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    buildSieve();

    int t;
    cin >> t;
    // t = 1;
    while (t--) {
        solve();
    }
    return 0;
}