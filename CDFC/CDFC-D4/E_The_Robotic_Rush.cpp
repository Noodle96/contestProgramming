/*
==========================================================
|  Archivo       : E_The_Robotic_Rush.cpp
|  Autor         : Russell
|  Fecha         : 2026-01-18
|--------------------------------------------------------
|  Tópicos utilizados:
|  - div4
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
    int n, m, k;
    cin >> n >> m >> k;

    vector<ll> robots(n);
    for (int i = 0; i < n; i++)
        cin >> robots[i];

    vector<ll> spikes(m);
    for (int i = 0; i < m; i++)
        cin >> spikes[i];

    string gdCode;
    cin >> gdCode;

    unordered_map<ll, int> firstTime;

    ll shift = 0;
    for (int i = 0; i < k; i++){
        if (gdCode[i] == 'L')
            shift--;
        else
            shift++;
        if (!firstTime.count(shift))
            firstTime[shift] = i;
    }

    sort(all(spikes));

    vector<int> deadAt(k, 0);

    for (int i = 0; i < n; i++){
        ll a = robots[i];
        ll L = a - (ll)k;
        ll R = a + (ll)k;

        int idxL = (int)(lower_bound(all(spikes), L) - spikes.begin());
        int idxR = (int)(upper_bound(all(spikes), R) - spikes.begin());

        int best = INT_MAX;

        for (int j = idxL; j < idxR; j++){
            ll need = spikes[j] - a;
            auto it = firstTime.find(need);
            if (it != firstTime.end())
                best = min(best, it->second);
        }

        if (best != INT_MAX)
            deadAt[best]++;
    }

    int alive = n;
    for (int i = 0; i < k; i++){
        alive -= deadAt[i];
        cout << alive << " ";
    }cout << endl;
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