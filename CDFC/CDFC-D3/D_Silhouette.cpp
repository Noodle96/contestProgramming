/*
==========================================================
|  Archivo       : D_Silhouette.cpp
|  Autor         : Russell
|  Fecha         : 2026-08-04 10:15
|--------------------------------------------------------
|  Tópicos utilizados:
|  - constructive algorithms
|  - sorting
|  - greedy
|  - math (divisibilidad)
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
    int n;
    cin >> n;
    vector<ll> b(n);
    for (auto &x : b) cin >> x;

    vector<pair<ll, int>> arr(n);
    for (int i = 0; i < n; i++) arr[i] = {b[i], i};
    sort(all(arr));

    vector<ll> values;
    vector<ll> cnt;
    vector<int> groupStart;
    int i = 0;
    while (i < n) {
        int j = i;
        ll val = arr[i].first;
        while (j < n && arr[j].first == val) j++;
        values.pb(val);
        cnt.pb(j - i);
        groupStart.pb(i);
        i = j;
    }

    int k = (int)values.size();

    if (values[0] != 0) {
        cout << -1 << "\n";
        return;
    }

    vector<ll> v(k);
    bool ok = true;
    for (int g = 0; g < k - 1 && ok; g++) {
        ll diff = values[g + 1] - values[g];
        if (diff % cnt[g] != 0) { ok = false; break; }
        v[g] = diff / cnt[g];
        if (g > 0 && v[g] <= v[g - 1]) { ok = false; break; }
    }

    if (!ok) {
        cout << -1 << "\n";
        return;
    }

    if (k == 1) v[0] = 1;
    else v[k - 1] = v[k - 2] + 1;

    vector<ll> a(n);
    for (int g = 0; g < k; g++) {
        int start = groupStart[g];
        int end = (g + 1 < k) ? groupStart[g + 1] : n;
        for (int t = start; t < end; t++) {
            a[arr[t].second] = v[g];
        }
    }

    for (int idx = 0; idx < n; idx++) {
        cout << a[idx] << " \n"[idx == n - 1];
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
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}