/*
==========================================================
|  Archivo       : B_Right_Maximum.cpp
|  Autor         : Russell
|  Fecha         : 2026-03-16 10:45
|--------------------------------------------------------
|  Tópicos utilizados:
|  - set
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
    set<int> s;
    vector<pair<int, int>> vp;
    for(int i = 0; i < n; i++){
        s.insert(i);
        int a;
        cin >> a;
        vp.emplace_back(a, i);
    }

    sort(all(vp), [&](pair<int,int> a, pair<int, int> b){
        if(a.first == b.first){
            return a.second > b.second; 
        }
        return a.first > b.first;
    });
    // cout << "print vp\n";
    // for(auto p: vp){
    //     cout << p.first << " " << p.second << endl;
    // }
    // cout << endl;
    int ans = 0;
    for(auto p: vp){
        auto f = s.find(p.second);
        if(f != s.end()){
            ans++;
            s.erase(f, s.end());
        }

    }
    // cout <<"ans: " <<ans << "\n";
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