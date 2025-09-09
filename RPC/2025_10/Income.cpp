/*
==========================================================
|  Archivo       : Income.cpp
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
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end(), greater<long long>());
    // // print a;
    // for(auto a_i: a) cout << a_i << " ";
    // return;

    __int128 S128 = 0;
    for (ll v : a) S128 += v;
    ld S = (ld)S128; // total como LD

    __int128 P128 = 0;
    ld best = 0.0L;
    for (int k = 1; k < n; ++k) {
        P128 += a[k-1];
        ld P = (ld)P128;
        ld delta = P / S - (ld)k / (ld)n;
        if (delta > best) best = delta;
    }

    ld ans = 100.0L * best;
    // cout.setf(std::ios::fixed); 
    cout << fixed << setprecision(6);
    cout << (double)ans << endl;
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