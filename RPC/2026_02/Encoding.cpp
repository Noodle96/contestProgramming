/*
==========================================================
|  Archivo       : Encoding.cpp
|  Autor         : Russell
|  Fecha         : 2026-03-14 14:51
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

void solve() {
    int n;
    cin >> n;
    map<int, int> cnt;
    int mx;
    for(int i = 0 ; i < n; i++){
        int a; cin >> a;
        cnt[a]++;
    }
    int ans_mx = -1;
    for(auto [k,v]: cnt){
        mx = k;
        // si maximo es par
        if(mx % 2 == 0){
            int i = (mx + 2) / 2;
            int freq = cnt[mx];
            int r;
            if(freq & 1){
                r = (freq - 1) / 2;
            }else{
                r = freq / 2;
            }
            // cout <<"\t"<< i + r << "\n";
            ans_mx = max(ans_mx, i + r);
        }else{
            // si maximo es impar
            int i = (mx + 3) / 2;
            int r;
            int freq = cnt[mx];
            if(freq & 1){
                r = (freq - 1) / 2;
            }else{
                r = (freq - 2) / 2;
            }
            // cout << "\t"<< i + r << "\n";
            ans_mx = max(ans_mx, i + r);
        }
    }
    cout << ans_mx << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;
    // cin >> t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}