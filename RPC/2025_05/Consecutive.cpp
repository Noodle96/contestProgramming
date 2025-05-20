/*
==========================================================
|  Archivo       : Consecutive.cpp
|  Autor         : Russell
|  Fecha         : 2025-05-17 17:09
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Bit Manipulation
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

// suma de popcounts desde 0 hasta n
ll S(ll n) {
    if (n < 0) return 0;
    ll res = 0;
    for (int k = 0; (1LL<<k) <= n; ++k) {
        ll len = 1LL << (k+1);
        ll full = (n+1) / len;
        ll rem = (n+1) % len;
        res += full * (1LL<<k) + max<ll>(0, rem - (1LL<<k));
    }
    return res;
}

// suma de floor(log2(i)) para i=1..n
ll L(ll n) {
    if (n <= 0) return 0;
    ll m = 63 - __builtin_clzll(n);  // floor(log2(n))
    ll P = 1LL << m;
    // T(m) = sum_{k=0..m-1} k*2^k = (m-2)*2^m + 2
    ll Tm = (m >= 1 ? (m-2) * P + 2 : 0);
    return Tm + m * (n - P + 1);
}

void solve(){
    ll l,r;
    cin>>l>>r;
    ll ans = (S(r) - S(l-1)) + (L(r) - L(l-1));
    cout << ans << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t; cin>>t;
    while(t--) solve();
    return 0;
}