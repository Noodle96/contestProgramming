/*
==========================================================
|  Archivo       : B_Beautiful_Numbers.cpp
|  Autor         : Russell
|--------------------------------------------------------
|  Tópicos utilizados:
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
    ll x;
    cin >> x;
    string s = to_string(x);
    int n = (int)s.size();

    int sum = 0;
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        d[i] = s[i] - '0';
        sum += d[i];
    }

    if (sum <= 9) {
        cout << 0 << "\n";
        return;
    }

    int R = sum - 9;
    vector<int> caps;
    caps.reserve(n);

    caps.push_back(d[0] - 1);

    for (int i = 1; i < n; i++) caps.push_back(d[i]);

    sort(caps.rbegin(), caps.rend());

    int reduced = 0, moves = 0;
    for (int cap : caps) {
        if (reduced >= R) break;
        if (cap <= 0) continue;
        reduced += cap;
        moves++;
    }
    cout << moves << "\n";
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