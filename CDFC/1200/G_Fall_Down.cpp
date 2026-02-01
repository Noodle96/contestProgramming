/*
==========================================================
|  Archivo       : G_Fall_Down.cpp
|  Autor         : Russell
|  Fecha         : 2026-02-01 17:11
|--------------------------------------------------------
|  Tópicos utilizados:
|  - implementation
|  - training
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
    int n,m; cin >> n >> m;
    vector<string> grid(n);
    vector<string> ans(m);
    for(int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    for(int col = 0; col < m; col++){
        int total = 0, stone = 0;
        vector<pair<int,int>> tempAns;
        bool lastWasStone = true;
        for(int row = 0; row < n; row++){
            if (grid[row][col] == '*'){
                stone++; total++;
            }
            else if(grid[row][col] == '.'){
                total++;
            }
            else if (grid[row][col] == 'o'){
                tempAns.pb(mp(stone,total));
                stone = 0; total = 0;
            }
        }
        if(total > 0){
            tempAns.pb(mp(stone,total));
            lastWasStone = false;
        }
        for(auto &p: tempAns){
            int dots = p.second - p.first;
            int stones = p.first;
            for(int i = 0 ; i < dots; i++)
                ans[col].push_back('.');
            for(int i = 0 ; i < stones; i++)
                ans[col].push_back('*');
            ans[col].push_back('o');
        }
        if(!lastWasStone)
            ans[col].pop_back();
    }
    for(int row = 0; row < n; row++){
        for(int col = 0; col < m; col++){
            cout << ans[col][row];
        }
        cout << "\n";
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