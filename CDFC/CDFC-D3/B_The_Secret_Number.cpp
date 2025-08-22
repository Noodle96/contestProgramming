/*
==========================================================
|  Archivo       : B_The_Secret_Number.cpp
|  Autor         : Russell
|  Fecha         : 2025-08-21 10:30
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Div3
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

ll myPow(ll base, ll exp) {
    ll ans = 1;
    while (exp > 0) {
        if (exp & 1) ans *= base;
        base *= base;
        exp >>= 1;
    }
    return ans;

}


void solve(){
    string number_str;
    cin >> number_str;
    ll num_ll = stoll(number_str);  
    int len = number_str.size();
    vector<ll> ans;
    for(int e = 1 ; e < len; e++){
        ll den = myPow(10, e) + 1;
        if(num_ll % den != 0) continue;
        // cout << "num_ll: " << num_ll<<" den: " << den << endl;
        ans.pb(num_ll / den);
    }
    sort(all(ans));
    if(ans.empty()){
        cout << 0 << endl;
        return;
    }
    cout << ans.size() << endl;
    // recorrer ans 
    for( auto a_i: ans){
        cout << a_i << " ";
    }cout << endl;
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