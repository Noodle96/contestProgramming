/*
==========================================================
|  Archivo       : B_Pleasant_Pairs.cpp
|  Autor         : Russell
|  Fecha         : 2025-11-13
|--------------------------------------------------------
|  Tópicos utilizados:
|  - training
|  - math
|  - number theory
|  - brute force
|  - *1200
==========================================================
*/

#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;

using ll = long long;
using i64 = int64_t;
using i32 = int32_t;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template <typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vll = vector<ll>;

#define pb push_back
#define mp make_pair

const int INF = 1e9;

ll gcd(ll a, ll b)
{
    if (a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}
ll floordiv(ll a, ll b)
{
    if (a >= 0)
        return a / b;
    return -((-a + b - 1) / b);
}
ll ceildiv(ll a, ll b)
{
    // ceil(a/b) = -floor((-a)/b)
    if (a >= 0)
        return (a + b - 1) / b;
    return -((-a) / b);
}
int bitlen_unsigned(unsigned long long n)
{
    // __builtin_clzll: Cuenta los ceros a la izquierda
    return (n == 0) ? 1 : 64 - __builtin_clzll(n);
}

clock_t startTime;
double getCurrentTime()
{
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
/*
    Queremos encontrar el k que satisfaga mk - r > r
    Asi,
        mk > 2r
        k > techo(2r/m)
    Pero si 2r/m es exacto entonces k debe ser mayor en 1 unidad

*/
int mayorCercano(int m, int r)
{
    int k = ceildiv(2 * r, m);
    if (2 * r % m == 0)
        k += 1;
    return m * k - r;
}

/*
    Dado que los numeros son todos diferentes, asi no nos preocupamos que siempre salte
    de 1 en 1.
    Asi, la compljidad de nuestra solucion es

    n + n/2 + n/3 + ... + n/n = n(1 + 1/2 + 1/3 + ... + 1/n) = n*O(log n) = O(n log n)
*/
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int idx1 = i;
        int number1 = a[i];
        // Aqui los saltos son de number1 en number1
        for (int j = mayorCercano(number1, idx1); j <= n; j += number1)
        {
            int idx2 = j;
            int number2 = a[j];
            // cout << "  idx2: " << idx2 << " number2: " << number2 << "\n";
            if (1LL * number1 * 1LL * number2 == idx1 + idx2)
                ans++;
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    // t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}