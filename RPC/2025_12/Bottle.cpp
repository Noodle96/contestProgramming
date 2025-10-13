/*
==========================================================
|  Archivo       : Bottle.cpp
|  Autor         : Russell
|  Fecha         : 2025-10-11 13:38
|--------------------------------------------------------
|  Tópicos utilizados:
|  - rpc
|  - math
|  - implementation
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
    ll d; cin >> d;
    ll a,o; cin >> a >> o;
    ll va,vo; cin >> va >> vo;
    ll remainA = max( 0LL, a - d * va);
    ll remainO = max( 0LL, o - d * vo);
    double ans = 100.0 *  ((1.0*remainA)/ (1.0*remainA + 1.0*remainO));
    cout << fixed << setprecision(14);
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
    //cin >> t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}