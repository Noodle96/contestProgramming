/*
==========================================================
|  Archivo       : B_Evanescent.cpp
|  Autor         : Russell
|  Fecha         : 2026-08-04 09:44
|--------------------------------------------------------
|  Tópicos utilizados:
|  - strings
|  - run-length encoding (compresion de bloques)
|  - greedy
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
    string s;
    cin >> s;

    // Descomponemos s en bloques (run-length): caracter + longitud del bloque.
    vector<char> ch;
    vector<int> len;
    for (int i = 0; i < n; i++) {
        if (!ch.empty() && ch.back() == s[i]) {
            len.back()++;
        } else {
            ch.pb(s[i]);
            len.pb(1);
        }
    }

    int B = (int)ch.size();

    bool hasLongBlock = false;
    for (int l : len) {
        if (l >= 2) { hasLongBlock = true; break; }
    }

    int ans = INF;

    if (hasLongBlock) ans = min(ans, B);
    for (int j = 1; j <= B - 2; j++) {
        if (len[j] == 1) {
            int candidate = (B - 1) - (ch[j - 1] == ch[j + 1] ? 1 : 0);
            ans = min(ans, candidate);
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
    while (t--) {
        solve();
    }
    return 0;
}