/*
==========================================================
|  Archivo       :  Addall.cpp
|  Autor         : Russell
|  Fecha         : 2025-05-17 15:11
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Tema 1
|  - Tema 2
|  - Tema 3
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
    int n;
    cin>>n;
    multiset<ll> s;
    for(int e = 0 ;e < n ; e++){
        ll a; cin>>a;
        s.insert(a);
    }
    // cout << "s.size()=" << s.size() << endl;
    ll ans = 0;
    while(s.size() >= 2){
        auto it = s.begin();
        ll a = *it;
        s.erase(it);
        // cout << "\ta= " << a << " size() " << s.size() << endl;;
        it = s.begin();
        ll b = *it;
        s.erase(it);
        // cout << "\tb= " << b << " size() " << s.size() << endl;;

        ll c = a + b;
        s.insert(c);
        // cout << "\tc= " << c << " size() " << s.size() << endl;;
        ans += c;
        // cout << "\t ans = " << ans << " ans size=" << s.size() <<  endl;
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
    int t; cin>>t;
    while(t--) solve();
    return 0;
}