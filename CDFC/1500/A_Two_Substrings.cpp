/*
==========================================================
|  Archivo       : A_Two_Substrings.cpp
|  Autor         : Russell
|  Fecha         : 2026-03-06 17:47
|--------------------------------------------------------
|  Tópicos utilizados:
|  - string
|  - bruteforce
|  - *1500
==========================================================
*/

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;
using i64 = int64_t;
using i32 = int32_t;
using ld = long double;
using ull = unsigned long long;
using uint = unsigned int;
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
    string s;
    cin >> s;
    int n = (int)s.size();
    auto check = [&](string x, string y) -> bool{
        for(int i = 0 ;i <  n - 1 ; i++){
            if(s.substr(i,2) == x){
                for(int j = i + 2; j < n - 1; j++){
                    if(s.substr(j, 2) == y) return true;
                }
                break;
            }
        }
        return false;
    };

    auto v1 = check("AB", "BA");
    auto v2 = check("BA", "AB");
    cout << ((v1 || v2) ? "YES": "NO") << "\n";
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