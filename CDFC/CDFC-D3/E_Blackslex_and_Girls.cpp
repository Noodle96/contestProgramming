/*
==========================================================
|  Archivo       : E_Blackslex_and_Girls.cpp
|  Autor         : Russell
|  Fecha         : 2025-12-23 11:14
|--------------------------------------------------------
|  Tópicos utilizados:
|  - div3
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
    ll x, y;
    cin >> n >> x >> y;
    string s; cin >> s;
    vector<ll> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];

    ll T = x + y;
    ll P = 0;
    for (ll pi : p)
        P += pi;

    if (T < P){
        cout << "NO" << endl;
        return;
    }

    int cntAwin = 0, cntBwin = 0;
    for (char c : s){
        if (c == '0')
            cntAwin++;
        else
            cntBwin++;
    }

    ll E = T - P;

    auto A_min_for_Awin = [&](ll pi) -> ll{
        return ceildiv(pi + 1, 2);
    };
    auto base_f_Awin = [&](ll pi) -> ll {
        return floordiv(pi, 2) + 1;
    };
    auto G_for_Bwin = [&](ll pi) -> ll {
        return floordiv(pi - 1, 2);
    };

    ll xmin = 0, xmax = 0;
    if (cntAwin > 0 && cntBwin > 0){
        ll sumPiB = 0;
        ll sumGpiB = 0;
        ll sumMinA_Awin = 0;
        for (int i = 0; i < n; i++){
            if (s[i] == '0'){
                sumMinA_Awin += A_min_for_Awin(p[i]);
            }
            else{
                sumPiB += p[i];
                sumGpiB += G_for_Bwin(p[i]);
            }
        }
        xmin = sumMinA_Awin;
        xmax = (T - sumPiB) + sumGpiB;
        cout << ((xmin <= x && x <= xmax) ? "YES\n" : "NO\n");
    }
    else if (cntBwin == 0){
        ll xbase = 0;
        ll evenCnt = 0;
        for (int i = 0; i < n; i++){
            xbase += base_f_Awin(p[i]);
            if ((p[i] % 2) == 0)
                evenCnt++;
        }
        ll extra = E;
        ll add = 0;
        if (extra > evenCnt){
            ll rem = extra - evenCnt;
            add = ceildiv(rem, 2);
        }
        xmin = xbase + add;
        xmax = T;
        cout << ((xmin <= x && x <= xmax) ? "YES\n" : "NO\n");
    }
    else{
        ll xbase = 0;
        ll evenCnt = 0;
        for (int i = 0; i < n; i++){
            xbase += G_for_Bwin(p[i]);
            if ((p[i] % 2) == 0)
                evenCnt++;
        }
        ll extra = E;
        ll gain = 0;
        if (extra <= evenCnt){
            gain = extra;
        }
        else{
            ll rem = extra - evenCnt;
            gain = evenCnt + (rem / 2);
        }
        xmin = 0;
        xmax = xbase + gain;
        cout << ((xmin <= x && x <= xmax) ? "YES\n" : "NO\n");
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
    cin >> t;
    // t = 1;
    while (t--) {
        solve();
    }
    return 0;
}