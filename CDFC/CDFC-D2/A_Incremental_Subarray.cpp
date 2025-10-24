/*
==========================================================
|  Archivo       : A_Incremental_Subarray.cpp
|  Autor         : Russell
|  Fecha         : 2025-09-24 06:56
|--------------------------------------------------------
|  Tópicos utilizados:
|  - implementation
|  - div2
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
    ll n; int m;
    cin >> n >> m;
    vector<ll> a(m);
    for (int i = 0; i < m; ++i) cin >> a[i];

    bool ok = true;
    vector<ll> ends;
    for (int i = 0; i < m - 1; ++i) {
        if (a[i+1] == a[i] + 1) {
        } else if (a[i+1] == 1) {
            ends.push_back(a[i]);
        } else {
            ok = false;
            break;
        }
    }
    if (!ok) {
        cout << 0 << "\n";
        return;
    }

    if (ends.empty()) {
        ll need = a[0] + (m - 1);
        ll ans = (need <= n) ? (n - need + 1) : 0;
        cout << ans << "\n";
    } else {
        for (int j = 0; j + 1 < (int)ends.size(); ++j) {
            if (ends[j+1] != ends[j] + 1) {
                ok = false; break;
            }
        }
        if (!ok) {
            cout << 0 << "\n";
            return;
        }
        ll s = ends[0];
        ll Kt = s + (ll)ends.size();
        if (Kt <= n && a.back() <= Kt) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
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