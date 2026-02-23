/*
==========================================================
|  Archivo       : C.cpp
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
struct Node {
    ll cnt = 0;   // how many subarrays have this current root s
    ll sumF = 0;  // sum of f over those subarrays
};

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    map<ll, Node> mp;   // key = current root s
    ll totalSumF = 0;   // sum of f for all subarrays ending at current r
    ll answer = 0;

    for (int r = 1; r <= n; r++) {
        ll v = a[r];

        if (r == 1) {
            // Only subarray [1..1]
            mp[v].cnt += 1;
            mp[v].sumF += 1;
            totalSumF = 1;
            answer += totalSumF;
            continue;
        }

        ll prev = a[r - 1];

        // Determine where to start merging (all roots >= startKey will reset)
        bool mergeAll = (v > prev + 1);

        ll mergedCnt = 0;
        ll mergedSum = 0;

        auto it = mergeAll ? mp.begin() : mp.lower_bound(v);
        while (it != mp.end()) {
            mergedCnt += it->second.cnt;
            mergedSum += it->second.sumF;

            totalSumF -= it->second.sumF;
            it = mp.erase(it);
        }

        if (mergedCnt > 0) {
            // After reset: each subarray in this merged group gets f += 1 and root becomes v
            // so sumF increases by mergedCnt
            mp[v].cnt += mergedCnt;
            mp[v].sumF += mergedSum + mergedCnt;
            totalSumF += mergedSum + mergedCnt;
        }

        // Add new subarray [r..r] with f=1 and root=v
        mp[v].cnt += 1;
        mp[v].sumF += 1;
        totalSumF += 1;

        // Contribution of all subarrays ending at r
        answer += totalSumF;
    }

    cout << answer << "\n";
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