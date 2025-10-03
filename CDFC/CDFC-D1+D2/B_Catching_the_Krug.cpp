/*
==========================================================
|  Archivo       : B_Catching_the_Krug.cpp
|  Autor         : Russell
|  Fecha         : 2025-10-03 09:52
|--------------------------------------------------------
|  Tópicos utilizados:
|  - implementation
|  - div1 + div2
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
    ll n, rK, cK, rD, cD;
    cin >> n >> rK >> cK >> rD >> cD;
    ll ans = 0;
    if (rK == rD) { // Misma Fila
        if (cD > cK) ans = cD;           // huye a la izquierda
        else         ans = n - cD;       // huye a la derecha
    } else if (cK == cD) { // Misma Columna
        if (rD > rK) ans = rD;           // huye hacia arriba
        else         ans = n - rD;       // huye hacia abajo
    } else {
        ll x = (rD > rK) ? 0 : n;
        ll y = (cD > cK) ? 0 : n;
        ans = max(abs(rD - x), abs(cD - y));
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