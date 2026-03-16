/*
==========================================================
|  Archivo       : Shinjuku.cpp
|  Autor         : Russell
|  Fecha         : 2026-03-14 13:40
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
    int n,m;
    string line;
    cin >> n >> m;
    vector<string> a, b;
    for(int i = 0 ; i < n ; i++){
        cin >> line;
        a.pb(line);
    }

    for(int i = 0 ; i < m ; i++){
        cin >> line;
        b.pb(line);
    }
    int s; cin >> s;

    auto getTime = [&](string str) -> tuple<int, int, int>{
        //11:00:00
        int h = stoi(str.substr(0,2));
        int m = stoi(str.substr(3,5));
        int s = stoi(str.substr(6,8));
        return{h,m,s};
    };

    auto f = [&](string format1, string format2) -> int{
        if(format1 < format2){
            auto [h1, m1, s1] = getTime(format1);
            auto [h2, m2, s2] = getTime(format2);
            int total1 = 3600 * h1 + 60 * m1 + s1;
            int total2 = 3600 * h2 + 60 * m2 + s2;
            int diference = total2 - total1;
            return diference;
        }
        return -1;
    };

    int ans = INF;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m; j++){
            int t = f(a[i], b[j]);
            if( t != -1 && t >= s){
                ans = min(ans, t);
            }
        }
    }
    if(ans == INF){
        cout << -1 << "\n";
    }else{
        cout << ans << "\n";
    }
}
void solve2(){
    
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