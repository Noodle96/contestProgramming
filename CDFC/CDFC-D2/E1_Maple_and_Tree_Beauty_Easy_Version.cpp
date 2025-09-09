/*
==========================================================
|  Archivo       : E1_Maple_and_Tree_Beauty_Easy_Version.cpp
|  Autor         : Russell
|  Fecha         : 2025-09-08
|--------------------------------------------------------
|  Tópicos utilizados:
|  - dfs and similars
|  - dp on trees
|  - graphs
==========================================================
*/

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;

using ll = long long;
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

const ll INF = 1e18;

ll gcd(ll a,ll b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

void solve(){
    int n, k;
        cin >> n >> k;
        vector<vector<int>> g(n + 1);
        for (int i = 2; i <= n; ++i) {
            int p; cin >> p;
            g[p].push_back(i);
        }

        vector<int> depth(n + 1, 0);
        queue<int> q;
        depth[1] = 1;
        q.push(1);

        int minLeafDepth = INT_MAX;
        vector<int> cntDepth(n + 2, 0);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            cntDepth[depth[u]]++;
            if (g[u].empty()) minLeafDepth = min(minLeafDepth, depth[u]);
            for (int v : g[u]) {
                depth[v] = depth[u] + 1;
                q.push(v);
            }
        }

        int Dmin = minLeafDepth;
        vector<int> B;
        B.reserve(Dmin);
        for (int d = 1; d <= Dmin; ++d) B.push_back(cntDepth[d]);

        vector<char> dp(k + 1, 0);
        dp[0] = 1;

        int ans = 0, S = 0;
        for (int i = 0; i < Dmin; ++i) {
            int w = B[i];
            S += w;
            for (int s = k; s >= w; --s)
                if (dp[s - w]) dp[s] = 1;

            int LB = max(0, S - (n - k));
            bool ok = false;
            if (LB <= k) {
                for (int s = LB; s <= k; ++s)
                    if (dp[s]) { ok = true; break; }
            }
            if (ok) ans = i + 1;
        }

        cout << ans << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;
    cin >> t;
    // t = 1;
    while(t--){
        solve();
    }
    return 0;
}