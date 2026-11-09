/*
==========================================================
|  Archivo       : C_Reverse_and_Double.cpp
|  Autor         : Russell
|  Fecha         : 2026-11-07
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

int n;
vector<ll> a, d;

bool can(ll X) {
    ll T = X / 2;
    int m = n - 1;
    vector<int> bad;
    bad.reserve(3);
    for (int i = 0; i < m; i++) {
        if (d[i] > X) {
            bad.push_back(i);
            if ((int)bad.size() > 2) return false;
        }
    }
    if (bad.empty()) return true;

    if ((int)bad.size() == 2) {
        int p1 = bad[0], p2 = bad[1];
        int l = p1 + 1, r = p2;
        if (l > r) return false;
        for (int i = l; i < r; i++) {
            if (d[i] > T) return false;
        }
        bool leftOK  = abs(a[p1] - 2 * a[r]) <= X;
        bool rightOK = abs(2 * a[l] - a[r + 1]) <= X;
        return leftOK && rightOK;
    }

    int p = bad[0];

    {
        int l = p + 1;
        int maxR = l;
        while (maxR < n - 1 && d[maxR] <= T) maxR++;
        for (int r = l; r <= maxR; r++) {
            bool leftOK  = abs(a[p] - 2 * a[r]) <= X;
            bool rightOK = (r == n - 1) ? true : (abs(2 * a[l] - a[r + 1]) <= X);
            if (leftOK && rightOK) return true;
        }
    }

    {
        int r = p;
        int minL = r;
        while (minL > 0 && d[minL - 1] <= T) minL--;
        for (int l = minL; l <= r; l++) {
            bool rightOK = abs(2 * a[l] - a[r + 1]) <= X;
            bool leftOK  = (l == 0) ? true : (abs(a[l - 1] - 2 * a[r]) <= X);
            if (leftOK && rightOK) return true;
        }
    }

    return false;
}


void solve() {
    cin >> n;
    a.assign(n, 0);
    for (auto &x : a) cin >> x;
    d.assign(n - 1, 0);
    for (int i = 0; i < n - 1; i++) d[i] = abs(a[i] - a[i + 1]);

    ll l = 0, r = 0;
    for (auto v : d) r = max(r, v);

    ll ans = -1;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        // buscamos el menor true valido
        if (can(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << "\n";
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