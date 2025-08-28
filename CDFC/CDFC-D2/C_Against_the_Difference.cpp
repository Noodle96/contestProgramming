/*
==========================================================
|  Archivo       : C_Against_the_Difference.cpp
|  Autor         : Russell
|  Fecha         : 2025-08-28
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Div 2
|  - Data Structure
|  - dp
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
    int n; 
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    vector<vector<int>> pos(n+1);
    vector<int> cnt(n+1, 0);
    vector<ll> dp(n+1, 0), pref(n+1, 0);

    for (int i = 1; i <= n; ++i) {
        int v = a[i];
        pos[v].push_back(i);
        cnt[v]++;

        dp[i] = dp[i-1];
        if (cnt[v] >= v) {
            int first_pos = pos[v][cnt[v] - v];
            ll base = (first_pos >= 2) ? pref[first_pos - 2] : 0;
        }
        int v2 = a[i];
        int c = cnt[v2];
        if (c >= v2) {
            int first_pos = pos[v2][c - v2];
            ll base = (first_pos - 1 >= 1) ? pref[first_pos - 1] : 0LL;
            dp[i] = max(dp[i], base + v2);
        }
        pref[i] = max(pref[i-1], dp[i]);
    }
    cout << dp[n] << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t; cin >> t;
    
    while(t--) solve();
    return 0;
}

/*
10
2 3 3 1 2 3 5 1 1 7
    [1] -> 4,8,9
    [2] -> 1,5
    [3] -> 2,3,6
    [5] -> 7
    [7] -> 10
*/