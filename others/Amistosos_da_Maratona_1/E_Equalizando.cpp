/*
==========================================================
|  Archivo       : E_Equalizando.cpp
|  Autor         : Russell
|  Fecha         : 2025-06-28 12:31
|--------------------------------------------------------
|  Tópicos utilizados:
|  - implementation
|  - greedy
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
    int n; cin >>n;
    string a, b;
    cin >> a >> b;
    int ans = 0;
    int e = 0;
    for( ;e < n-1 ; e++){
        if(a[e] == b[e]) continue;
        // son diferentes
        if(a[e+1] != b[e+1] && a[e] != a[e+1]){
            ans += 1;
            e += 1;
        }else{
            ans += 1;
        }
    }
    if( e == n-1 && a[e] != b[e]){
        ans += 1;
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