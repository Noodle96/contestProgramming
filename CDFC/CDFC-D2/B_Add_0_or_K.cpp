/*
==========================================================
|  Archivo       : B_Add_0_or_K.cpp
|  Autor         : Russell
|  Fecha         : 2025-08-26 10:02
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

ll smallest_prime_factor(ll x){
    if (x % 2 == 0) return 2;
    for (ll d = 3; d * d <= x; d += 2)
        if (x % d == 0) return d;
    return x;
}
void solve(){
    int n; ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    // p | (k+1)
    ll p = smallest_prime_factor(k + 1);
    for (int i = 0; i < n; ++i){
        ll mi = a[i] % p;
        a[i] += mi * k;
    }

    for (int i = 0; i < n; ++i){
        if (i) cout << ' ';
        cout << a[i];
    }
    cout << '\n';
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