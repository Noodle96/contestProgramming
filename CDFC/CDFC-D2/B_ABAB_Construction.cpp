/*
==========================================================
|  Archivo       : D.cpp
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

char letter_from_parity(int parity) {
    // parity: 1 -> odd -> 'a', 0 -> even -> 'b'
    return parity ? 'a' : 'b';
}

void solve() {
    int n;
    string X;
    cin >> n >> X;

    int mask = (1 << 1);

    for (int i = 1; i <= n; i++) {
        int m = n - i + 1;
        char need = X[i - 1];
        int newmask = 0;

        for (int p = 0; p <= 1; p++) {
            if (!(mask & (1 << p))) continue;

            char leftChar = letter_from_parity(p);

            int pr = (m % 2 == 1) ? p : (1 - p);
            char rightChar = letter_from_parity(pr);

            if (need == '?' || need == leftChar) {
                newmask |= (1 << (1 - p));
            }
            if (need == '?' || need == rightChar) {
                newmask |= (1 << p);
            }
        }

        mask = newmask;
        if (mask == 0) break;
    }

    cout << (mask ? "YES\n" : "NO\n");
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