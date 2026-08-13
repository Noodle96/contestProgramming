/*
==========================================================
|  Archivo       : B_Evanescent2.cpp
|  Autor         : Russell
|  Fecha         : 2026-08-12 17:12
|--------------------------------------------------------
|  Tópicos utilizados:
|  - ssting
|  - implementation
|  - div3
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
    string str;
    cin >> str;
    int index_delete = -1;
    set<int> set1,set2, set3,set4; 
    for(size_t i = 1; i < n - 1 ; i++){
        if(str[i-1] == str[i+1] && str[i] != str[i+1]) set1.insert(i);
        if(str[i-1] != str[i] && str[i] != str[i+1]) set2.insert(i);
        if((str[i-1] == str[i] && str[i] != str[i+1] ) || str[i] == str[i+1] && str[i] != str[i-1]) set3.insert(i);
        if(str[i-1] == str[i] && str[i] == str[i+1]) set4.insert(i);
    }
    if(set1.size() > 0) index_delete = *set1.begin();
    else if(set2.size() > 0) index_delete = *set2.begin();
    else if(set3.size() > 0) index_delete = *set3.begin();
    else if(set4.size() > 0) index_delete = *set4.begin();  
    str.erase(index_delete,1);
    auto compress = [](string &s) -> int {
        string res;
        for (char c : s) {
            if (res.empty() || res.back() != c) {
                res.push_back(c);
            }
        }
        return res.length();
    };
    int len = compress(str);
    cout << len << "\n";
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