/*
==========================================================
|  Archivo       : J1_Send_the_Fool_Further_easy.cpp
|  Autor         : Russell
|  Fecha         : 2026-03-08 18:53
|--------------------------------------------------------
|  Tópicos utilizados:
|  - dfs and similar: dfs
|  - graphs
|  - trees
|  - *1400
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
    vector<vector<pair<int,int>>> adjList(n, vector<pair<int,int>>());
    vector<bool> isVisited(n, false);
    for(int i = 0; i< n - 1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adjList[a].emplace_back(b,c);
        adjList[b].emplace_back(a,c);
    }

    auto dfs = [&](auto&& self, int u) -> int{
        isVisited[u] = true;
        int mx = 0;
        for(auto &[v,w]: adjList[u]){
            if(!isVisited[v]){
                int partial = self(self,v);
                mx = max(mx, partial + w);
            }
        }
        return mx;
    };

    // is a tree empezamos de 0
    auto maximo = dfs(dfs, 0);
    cout << maximo << "\n";
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