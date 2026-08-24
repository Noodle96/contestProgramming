/*
==========================================================
|  Archivo       : E_Binary_Deque.cpp
|  Autor         : Russell
|  Fecha         : 2026-08-24 18:09
|--------------------------------------------------------
|  Tópicos utilizados:
|  - binary search
|  - prefix sums
|  - *1200
|  - training
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
    int n, s;
    cin >> n >> s;
    int sum = 0;
    vector<int> a(n);
    for(int e = 0 ; e < n; e++){
        int x; cin >> x;
        a[e] = x;
        sum += x;
    }
    if(sum < s){
        cout << -1 << "\n";
        return;
    }
    if(sum == s){
        cout << 0 << "\n";
        return;
    }
    int deleteOnes = sum - s;
    vector<int> left_prefix_sum(n+1, 0);
    vector<int> right_prefix_sum(n+1, 0);
    
    for(int i = 1; i <= n;i++ ){
        left_prefix_sum[i] = left_prefix_sum[i-1] + a[i-1];
    }
    reverse(all(a));
    for(int i = 1; i <= n; i++){
        right_prefix_sum[i] = right_prefix_sum[i-1] + a[i-1];
    }
    int ans = INF;
    for(int a = 0; a <= deleteOnes; a++){
        int b = deleteOnes - a;
        auto it = lower_bound(all(left_prefix_sum), a);
        auto et = lower_bound(all(right_prefix_sum), b);
        int pos_a = (it - left_prefix_sum.begin());
        int pos_b = (et - right_prefix_sum.begin());
        ans = min(ans, pos_a + pos_b);
    }
    cout << ans << "\n";
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