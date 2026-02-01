/*
==========================================================
|  Archivo       : F_Eating_Candies.cpp
|  Autor         : Russell
|  Fecha         : 2026-02-01 17:50
|--------------------------------------------------------
|  Tópicos utilizados:
|  - prefix sum
|  - binary search
|  - training
|  - *1100
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
    int n; cin >> n;
    vector<int> w(n);
    int total = 0;
    for (int i = 0; i < n; i++){
        cin >> w[i];
        total += w[i];
    }
    total /=2;
    vector<int> prefixSumAlice(n), prefixSumBob(n);
    prefixSumAlice[0] = w[0];
    prefixSumBob[0] = w[n - 1];
    for(int i = 1 ; i < n; i++){
        prefixSumAlice[i] = prefixSumAlice[i - 1] + w[i];
        prefixSumBob[i] = prefixSumBob[i - 1] + w[n - 1 - i];
    }
    vector<int> aliceFilter, bobFilter;
    for(auto ps: prefixSumAlice){
        if (ps <= total){
            aliceFilter.push_back(ps);
        }
    }
    for(auto ps: prefixSumBob){
        if (ps <= total){
            bobFilter.push_back(ps);
        }
    }

    int n_alice = aliceFilter.size();

    for(int i = n_alice - 1; i >= 0; i--){
        int totalAlice = i+1;
        int totalBob = 0;
        auto it = lower_bound(all(bobFilter), aliceFilter[i]);
        if(it != bobFilter.end()){
            if(*it == aliceFilter[i]){
                totalBob = it - bobFilter.begin() + 1;
                cout << totalAlice + totalBob << "\n";
                return;
            }
        }
    }
    cout << 0 << "\n";
}
void test(){
    vector<int> w = {4,7,11};
    auto it =upper_bound(all(w),15);
    cout << *it << "\n";
    // if(it != w.end()){
    // }   
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
    // test();
    return 0;
}