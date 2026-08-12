/*
==========================================================
|  Archivo       : C2_Marenol.cpp
|  Autor         : Russell
|  Fecha         : 2026-08-04 10:04
|--------------------------------------------------------
|  Tópicos utilizados:
|  - constructive algorithms / invariants
|  - greedy (matching ordenado de posiciones)
|  - strings
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
    string a, b;
    cin >> a >> b;

    vector<int> idxA_odd, idxB_odd, idxA_even, idxB_even;
    int oddCount = 0, evenCount = 0;

    for (int i = 0; i < n; i++) {
        int pos = i + 1; // 1-indexado
        if (pos % 2 == 1) {
            oddCount++;
            if (a[i] == '1') idxA_odd.pb(oddCount);
            if (b[i] == '1') idxB_odd.pb(oddCount);
        } else {
            evenCount++;
            if (a[i] == '1') idxA_even.pb(evenCount);
            if (b[i] == '1') idxB_even.pb(evenCount);
        }
    }

    if (idxA_odd.size() != idxB_odd.size() || idxA_even.size() != idxB_even.size()) {
        cout << -1 << "\n";
        return;
    }

    ll ans = 0;
    for (size_t k = 0; k < idxA_odd.size(); k++) {
        ans += llabs((ll)idxA_odd[k] - (ll)idxB_odd[k]);
    }
    for (size_t k = 0; k < idxA_even.size(); k++) {
        ans += llabs((ll)idxA_even[k] - (ll)idxB_even[k]);
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
    while (t--) {
        solve();
    }
    return 0;
}