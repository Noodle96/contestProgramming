/*
==========================================================
|  Archivo       : B_Cake_Collection.cpp
|  Autor         : Russell
|  Fecha         : 2025-09-08 09:50
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
    int n;
    ll m;
    cin >> n >> m;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    sort(a.begin(), a.end(), greater<ll>());

    ll k = min((ll)n, m);
    ll start = m;
    ll ans = 0;

    for (ll i = 0; i < k; ++i) {
        ans += a[i] * (start - i);
    }
    cout << ans << "\n";
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