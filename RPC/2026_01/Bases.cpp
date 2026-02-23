/*
==========================================================
|  Archivo       : Bases.cpp
|  Autor         : Russell
|  Fecha         : 2026-02-21 13:34
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

bool toBaseValue(const string &s, int base, int &outVal)
{
    ll val = 0;
    for (char c : s)
    {
        int d = c - '0';
        if (d < 0 || d >= base)
            return false;
        val = val * base + d;
    }
    outVal = (int)val;
    return true;
}

void solve() {
    string X, Y;
    int S;
    cin >> X >> Y >> S;

    for (int bx = 2; bx <= 10; bx++)
    {
        int vx = 0;
        if (!toBaseValue(X, bx, vx))
            continue;

        for (int by = 2; by <= 10; by++)
        {
            int vy = 0;
            if (!toBaseValue(Y, by, vy))
                continue;

            if (vx + vy == S)
            {
                cout << bx << " " << by << "\n";
                return;
            }
        }
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
    // cin >> t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}