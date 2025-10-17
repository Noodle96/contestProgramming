/*
==========================================================
|  Archivo       : C_MEX_rose.cpp
|  Autor         : Russell
|  Fecha         : 2025-09-25
|--------------------------------------------------------
|  Tópicos utilizados:
|  - implementation
|  - div3
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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int> cnt(n + 1, 0);
    for (int v : a) cnt[v]++;

    int mex = 0;
    while (mex <= n && cnt[mex] > 0) ++mex;

    int cntk = (k <= n ? cnt[k] : 0);

    if (k == mex) {
        cout << 0 << endl;
        return;
    }

    if (k < mex) {
        cout << cntk << endl;
        return;
    }

    int missing = 0;
    for (int x = 0; x < k; ++x) {
        if (cnt[x] == 0) ++missing;
    }
    cout << max(missing, cntk) << endl;
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