/*
==========================================================
|  Archivo       : Around.cpp
|  Autor         : Russell
|  Fecha         : 2025-09-06
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
    ll l, r; 
    cin >> l >> r;
    ll N = l + r;
    set<ll> S = (l <= r) ? set<ll>{l-1, l}
                                : set<ll>{r, r+1};
    set<ll> M;
    for (auto s : S) M.insert(min(s, N - s)); // distancia mínima
    ll ans = 0;
    for (auto d : M)
        ans += (N % 2 == 0 && d == N/2) ? N/2 : N;
    cout << ans << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    solve();
    return 0;
}