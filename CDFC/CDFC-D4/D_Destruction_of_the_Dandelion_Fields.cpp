/*
==========================================================
|  Archivo       : D_Destruction_of_the_Dandelion_Fields.cpp
|  Autor         : Russell
|  Fecha         : 2025-09-13 09:58
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Div 4
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
    int n; cin >> n;
    vector<ll> odd;
    ll even = 0;
    for(int e = 0 ;e < n ; e++){
        ll a; cin >> a;
        if(a & 1) odd.pb(a);
        else even += a;
    }
    sort(all(odd), greater<ll>());
    if(odd.size() == 0){
        cout << 0 << endl;
        return;
    }
    int k = (odd.size() + 1)/2;;
    ll ans = even;
    for(int  e = 0 ;e < k ; e++){
        ans += odd[e];
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