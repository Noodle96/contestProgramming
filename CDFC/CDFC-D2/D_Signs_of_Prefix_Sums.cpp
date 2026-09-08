/*
==========================================================
|  Archivo       : D_Signs_of_Prefix_Sums.cpp
|  Autor         : Russell
|  Fecha         : 2026-09-08
|--------------------------------------------------------
|  Tópicos utilizados:
|  - contest
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
int n;
string s;

bool feasible(int K){
    int OFF = K + 1;
    int size = 2*OFF + 1;
    vector<char> reach(size, 0), nreach(size, 0);
    vector<int> pref(size+1, 0);
    reach[OFF] = 1;
    for(int i = 0; i < n; i++){
        pref[0] = 0;
        for(int j = 0; j < size; j++)
            pref[j+1] = pref[j] + reach[j];
        fill(nreach.begin(), nreach.end(), 0);
        char c = s[i];
        int lo_v, hi_v;
        if(c == '+'){
            lo_v = 1;
            hi_v = OFF;
        }else if(c == '-'){
            lo_v = -OFF;
            hi_v = -1; 
        }else {
            lo_v = 0;
            hi_v = 0;
        }
        bool any = false;
        for(int v = lo_v; v <= hi_v; v++){
            int idx = v + OFF;
            int lIdxLo = max(0, idx-K), lIdxHi = idx-1;
            int rIdxLo = idx+1, rIdxHi = min(size-1, idx+K);
            int cl = 0, cr = 0;
            if(lIdxHi >= lIdxLo) cl = pref[lIdxHi+1] - pref[lIdxLo];
            if(rIdxHi >= rIdxLo) cr = pref[rIdxHi+1] - pref[rIdxLo];
            if(cl > 0 || cr > 0){
                nreach[idx] = 1;
                any = true;
            }
        }
        swap(reach, nreach);
        if(!any) return false;
    }
    return true;
}

void solve() {
    cin >> n >> s;
    bool impossible = (s[0] == '0');
    for(int i = 1; i < n && !impossible; i++){
        if(s[i] == '0' && s[i-1] == '0') impossible = true;
    }

    if(impossible){
        cout << -1 << '\n';
        return;
    }

    int lo = 1, hi = 60;
    while(!feasible(hi)) hi *= 2;
    while(lo < hi){
        int mid = (lo + hi) / 2;
        if(feasible(mid))
            hi = mid;
        else lo = mid + 1;
    }
    cout << lo << '\n';
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