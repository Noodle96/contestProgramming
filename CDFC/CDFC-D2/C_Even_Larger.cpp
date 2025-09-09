/*
==========================================================
|  Archivo       : C_Even_Larger.cpp
|  Autor         : Russell
|  Fecha         : 2025-08-26 10:49
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Div 2
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
    vector<long long> a(n+2, 0);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    ll keep_sum = 0;
    ll prev_x = 0;
    for (int i = 1; i <= n; i += 2) {
        ll cap_self = a[i];
        ll cap_from_prev_even = (i > 1) ? max(0LL, a[i-1] - prev_x) : INF;
        ll cap_from_next_even = (i+1 <= n) ? a[i+1] : INF;
        ll xi = min(cap_self, min(cap_from_prev_even, cap_from_next_even));
        keep_sum += xi;
        prev_x = xi;
    }
    ll odd_sum = 0;
    for (int i = 1; i <= n; i += 2) odd_sum += a[i];

    ll ans = odd_sum - keep_sum;
    cout << ans << endl;
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