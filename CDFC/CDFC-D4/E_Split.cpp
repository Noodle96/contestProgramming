/*
==========================================================
|  Archivo       : E_Split.cpp
|  Autor         : Russell
|  Fecha         : 2025-09-13
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Implementation
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
    int n, k;  cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int> tot(n + 1, 0);
    for (int x : a) ++tot[x];

    bool ok = true;
    for (int v = 1; v <= n; ++v) {
        if (tot[v] % k != 0){
            ok = false;
            break;
        }
    }
    if (!ok){
        cout << 0 << endl;
        return;
    }
    vector<int> cap(n + 1, 0);
    for (int v = 1; v <= n; ++v)
        cap[v] = tot[v] / k;

    vector<int> freq(n + 1, 0);
    ll ans = 0;
    int r = 0;
    for (int l = 0; l < n; ++l) {
        while (r < n && freq[a[r]] < cap[a[r]]) {
            ++freq[a[r]];
            ++r;
        }
        ans += (r - l);
        --freq[a[l]];
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