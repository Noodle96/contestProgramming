/*
==========================================================
|  Archivo       : Picturecap.cpp
|  Autor         : Russell
|  Fecha         : 2026-02-21 15:24
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
    ll n, k;
    cin >> n >> k;

    vector<ll> c(n);
    for (ll i = 0; i < n; i++)
        cin >> c[i];

    ll left = *max_element(c.begin(), c.end());
    ll right = 0;

    // suma total + espacios máximos posibles
    for (ll i = 0; i < n; i++)
        right += c[i];
    right += (n - 1);

    ll ans = right;

    while (left <= right)
    {
        ll mid = (left + right) / 2;

        ll lines = 1;
        ll current_length = 0;
        ll names_in_line = 0;

        for (ll i = 0; i < n; i++)
        {

            ll extra = c[i];
            if (names_in_line > 0)
                extra += 1; // espacio

            if (current_length + extra <= mid)
            {
                current_length += extra;
                names_in_line++;
            }
            else
            {
                lines++;
                current_length = c[i];
                names_in_line = 1;
            }
        }

        if (lines <= k)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << ans << endl;
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