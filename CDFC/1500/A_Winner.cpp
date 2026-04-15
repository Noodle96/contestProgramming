/*
==========================================================
|  Archivo       : A_Winner.cpp
|  Autor         : Russell
|  Fecha         : 2026-04-14 19:03
|--------------------------------------------------------
|  Tópicos utilizados:
|  - implementation
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
    map<string, int> final_score;
    vector<pair<string, int>>  scores;
    for(int i = 0; i < n; i++){
        string name; cin >> name;
        int score; cin >> score;
        final_score[name] += score;
        scores.emplace_back(name, score);
    }
    int mx = -1e6;
    for(auto &[name, score]: final_score){
        mx = max(mx, score);
    }
    // recorremos scores para determinar quien ha llegado primero a mx
    map<string, int> current_score;
    for(auto &[name, score]: scores){
        current_score[name] += score;
        if(current_score[name] == mx && final_score[name] == mx){
            cout << name << "\n";
            return;
        }
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
    // cin >> t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}