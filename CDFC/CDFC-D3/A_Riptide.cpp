/*
==========================================================
|  Archivo       : A_Tokens.cpp
|  Autor         : Russell
|  Fecha         : 2026-08-04 09:36
|--------------------------------------------------------
|  Tópicos utilizados:
|  - simulation
|  - brute force
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
    array<int, 3> tok;
    for (auto &x : tok) cin >> x;

    int rounds = 0;
    while (true) {
        if (tok[0] == tok[1] || tok[1] == tok[2] || tok[0] == tok[2]) break;

        int idxMax = 0, idxMin = 0;
        for (int i = 1; i < 3; i++) {
            if (tok[i] > tok[idxMax]) idxMax = i;
            if (tok[i] < tok[idxMin]) idxMin = i;
        }
        tok[idxMax]--;
        tok[idxMin]++;
        rounds++;
    }

    cout << rounds << "\n";
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