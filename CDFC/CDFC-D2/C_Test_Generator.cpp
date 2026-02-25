/*
==========================================================
|  Archivo       : C_Test_Generator.cpp
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

pair<ll,ll> restrict_parity(ll L, ll H, int p) {
    if (L > H) return {1, 0};
    if ((L & 1) != p) L++;
    if ((H & 1) != p) H--;
    if (L > H) return {1, 0};
    return {L, H};
}

pair<ll,ll> interval_to_parity(ll L, ll H, int p) {
    return restrict_parity(L, H, p);
}

bool feasible(ll s, ll m, ll n) {
    pair<ll,ll> cur[2];
    cur[0] = {0, 0};
    cur[1] = {1, 0};

    for (int bit = 0; bit < 64; bit++) {
        int sb = (s >> bit) & 1LL;
        int mb = (m >> bit) & 1LL;

        pair<ll,ll> nxt[2] = { {1,0}, {1,0} };

        if (mb == 0) {
            auto interval = cur[sb];
            if (interval.first > interval.second) return false;

            ll L = interval.first / 2;
            ll H = interval.second / 2;

            nxt[0] = interval_to_parity(L, H, 0);
            nxt[1] = interval_to_parity(L, H, 1);
        } else {
            for (int p = 0; p < 2; p++) {
                auto interval = cur[p];
                if (interval.first > interval.second) continue;

                int r = sb ^ p;

                ll cmin = r;
                ll cmax = (n % 2 == r) ? n : (n - 1);

                if (cmax < cmin) continue;

                ll L2 = (interval.first + cmin) / 2;
                ll H2 = (interval.second + cmax) / 2;

                for (int np = 0; np < 2; np++) {
                    auto add = interval_to_parity(L2, H2, np);
                    if (add.first > add.second) continue;

                    if (nxt[np].first > nxt[np].second) {
                        nxt[np] = add;
                    } else {
                        nxt[np].first = min(nxt[np].first, add.first);
                        nxt[np].second = max(nxt[np].second, add.second);
                        nxt[np] = restrict_parity(nxt[np].first, nxt[np].second, np);
                    }
                }
            }
            if (nxt[0].first > nxt[0].second && nxt[1].first > nxt[1].second) return false;
        }

        cur[0] = nxt[0];
        cur[1] = nxt[1];
    }
    bool ok0 = (cur[0].first <= 0 && 0 <= cur[0].second);
    return ok0;
}

void solve() {
    ll s, m;
    cin >> s >> m;

    ll lo = ceildiv(s, m);
    ll hi = s;
    if (lo < 1) lo = 1;

    if (!feasible(s, m, hi)) {
        cout << -1 << "\n";
        return;
    }

    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if (feasible(s, m, mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << "\n";
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