/*
==========================================================
|  Archivo       :  B_Drifting_Away.cpp
|  Autor         : Russell
|  Fecha         : 2025-11-14 09:44
|--------------------------------------------------------
|  Tópicos utilizados:
|  - div2
==========================================================
*/

#include <bits/stdc++.h>
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

void solve()
{
    string s;
    cin >> s;
    int n = (int)s.size();

    bool infinite = false;
    for (int i = 0; i + 1 < n; ++i)
    {
        if ((s[i] == '>' || s[i] == '*') &&
            (s[i + 1] == '<' || s[i + 1] == '*'))
        {
            infinite = true;
            break;
        }
    }
    if (infinite)
    {
        cout << -1 << '\n';
        return;
    }

    int N = n + 1;
    vector<vector<int>> g(N);

    auto add_edge = [&](int from, int to)
    {
        g[from].pb(to);
    };

    for (int i = 1; i <= n; ++i)
    {
        char c = s[i - 1];
        if (c == '<')
        {
            int to = (i == 1 ? 0 : i - 1);
            add_edge(i, to);
        }
        else if (c == '>')
        {
            int to = (i == n ? 0 : i + 1);
            add_edge(i, to);
        }
        else
        {
            int toL = (i == 1 ? 0 : i - 1);
            int toR = (i == n ? 0 : i + 1);
            add_edge(i, toL);
            add_edge(i, toR);
        }
    }

    vector<int> vis(N, 0);
    vector<int> order;
    auto dfs = [&](int v, const auto &self) -> void
    {
        vis[v] = 1;
        for (int u : g[v])
        {
            if (!vis[u])
                self(u, self);
        }
        order.push_back(v);
    };

    for (int v = 0; v < N; ++v)
    {
        if (!vis[v])
            dfs(v, dfs);
    }
    vector<int> dp(N, 0);
    for (int v : order)
    {
        int best = 0;
        for (int u : g[v])
        {
            best = max(best, 1 + dp[u]);
        }
        dp[v] = best;
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        ans = max(ans, dp[i]);
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

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