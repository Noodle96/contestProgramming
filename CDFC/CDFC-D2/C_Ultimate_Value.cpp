/*
==========================================================
|  Archivo       : C_Ultimate_Value.cpp
|  Autor         : Russell
|  Fecha         : 2025-09-09
|--------------------------------------------------------
|  Tópicos utilizados:
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
    int n; cin >> n;
    vector<ll> a(n+1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    ll S0 = 0;
    for (int i = 1; i <= n; ++i)
        S0 += ( (i&1) ? a[i] : -a[i] );

    ll deltaSame = 0;
    if (n >= 2) deltaSame = (n % 2 ? n - 1 : n - 2);

    ll bestOE = LLONG_MIN;
    ll minOddPref = LLONG_MAX;
    for (int i = 1; i <= n; ++i) {
        if (i & 1) {
            minOddPref = min(minOddPref, 2*a[i] + (ll)i);
        } else {
            if (minOddPref != LLONG_MAX) {
                bestOE = max(bestOE, (2*a[i] + (ll)i) - minOddPref);
            }
        }
    }

    ll minOddSuf = LLONG_MAX;
    for (int i = n; i >= 1; --i) {
        if (i & 1) {
            minOddSuf = min(minOddSuf, 2*a[i] - (ll)i);
        } else {
            if (minOddSuf != LLONG_MAX) {
                bestOE = max(bestOE, (2*a[i] - (ll)i) - minOddSuf);
            }
        }
    }

    if (bestOE < 0) bestOE = 0;
    ll bestDelta = max({0LL, deltaSame, bestOE});
    ll ans = S0 + bestDelta;
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