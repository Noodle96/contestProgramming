/*
==========================================================
|  Archivo       : B_Discounts.cpp
|  Autor         : Russell
|  Fecha         : 2025-09-17
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Implementation
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
    int n, k; 
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> b(k);
    for (int i = 0; i < k; ++i) cin >> b[i];

    sort(a.begin(), a.end(), greater<ll>());
    sort(b.begin(), b.end());

    ll total = 0;
    for (ll v : a) total += v;

    ll discount = 0;
    int idx = 0;
    for (int x : b) {
        if (idx + x > n) break;
        discount += a[idx + x - 1];
        idx += x;
    }
    cout << (total - discount) << endl;
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