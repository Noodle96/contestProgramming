/*
==========================================================
|  Archivo       : A_Sequence_with_Digits.cpp
|  Autor         : Russell
|  Fecha         : 2026-10-26 16:01
|--------------------------------------------------------
|  Tópicos utilizados:
|  - brute force
|  - math
|  - convergence
|  - *1200
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
    ll a1, k;
    cin >> a1 >> k;
    set<ll> vals;
    vector<ll> seq;
    ll cont = 1;
    vals.insert(a1);
    seq.pb(a1);
    ll last = a1;
    auto min_max = [](ll val) -> pair<ll,ll> {
        ll min_digit = 9;
        ll max_digit = 0;
        while(val > 0){
            ll digit = val % 10;
            min_digit = min(min_digit, digit);
            max_digit = max(max_digit, digit);
            val /= 10;
        }
        return {min_digit, max_digit};
    };
    while(cont <= k){
        auto [min_digit, max_digit] = min_max(last);
        if(min_digit == 0) break;
        last += min_digit * max_digit;
        vals.insert(last);
        seq.pb(last);
        cont++;
    }
    int sz = vals.size();
    if(k > sz){
        cout << *vals.rbegin() << "\n";
    }else{
        cout << seq[k-1] << "\n";
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