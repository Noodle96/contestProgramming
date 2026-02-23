/*
==========================================================
|  Archivo       : Grimms.cpp
|  Autor         : Russell
|  Fecha         : 2026-02-21 13:07
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

map<string, int> memo;
void pre(){
    memo["Animal Appendages"] = 1;
    memo["Bewitched Broomstick"] = 3;
    memo["Cinderella’s Chore"] = 5;
    memo["Delicious Disaster"] = 7;
    memo["Evening Entertainment"] = 9;
    memo["Forgotten Fragments"] = 11;
    memo["Grimms’ Fairy Tales"] = 13;
    memo["Hansel and Gretel"] = 15;
    memo["Ignoble Imp"] = 17;
    memo["Jaded Journey"] = 19;
    memo["Knavish Knockout"] = 21;
    memo["Lucky Hans"] = 23;
    memo["Mother Hulda"] = 25;
}
void solve() {
    string s;
    getline(cin, s);
    cout << memo[s] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    pre();
    int t;
    // cin >> t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}