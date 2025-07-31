/*
==========================================================
|  Archivo       : Minitetris.cpp
|  Autor         : Russell
|  Fecha         : 2025-07-26 13:57
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
    int a,b,c;
    cin>>a>>b>>c;
    ll ans = 0;
    ans += a*2;
    if(c == 0){
        // nothing to do
    }else if(c == 1){
        // ans += (2*b+1);
        // nothing to do
    }else if(c == 2){
        ans += (2*b+3);
    }else{
        ans += (2*b+3);
        c -=2;
        ans += ((c/2)*3);
        // if(c&1) ans += 1;
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
    solve();
    return 0;
}