/*
==========================================================
|  Archivo       : C1_The_Cunning_Seller_easy_version.cpp
|  Autor         : Russell
|  Fecha         : 2025-08-21 11:15
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Div 3
|  - Greedy
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

vector<ll> qty, cost;


void precompute() {
    ll p = 1; // 3^0
    for (int x = 0; ; x++) {
        if (p > 1e9) break;
        ll c;
        if (x == 0) c = 3;
        else c = (p * 3) + x * (p / 3); // 3^(x+1) + x*3^(x-1)
        qty.push_back(p);
        cost.push_back(c);
        if (p > 1e9 / 3) break; // evitar overflow
        p *= 3;
    }
}

void solve(){
    ll n;
    cin >> n;
    ll ans = LLONG_MAX;

    // Opción 1: un solo deal >= n
    for (int i = 0; i < (int)qty.size(); i++) {
        if (qty[i] >= n) {
            ans = min(ans, cost[i]);
        }
    }

    // Opción 2: combinación de deals (como en base 3)
    ll tmp = 0;
    ll m = n;
    for (int i = (int)qty.size() - 1; i >= 0; i--) {
        ll take = m / qty[i]; // aquí sí permitimos más de 1
        tmp += take * cost[i];
        m -= take * qty[i];
    }
    if (m == 0) ans = min(ans, tmp);

    cout << ans << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    precompute();
    int t; cin >> t;
    while(t--) solve();
    return 0;
}