/*
==========================================================
|  Archivo       : A_Be_Positive.cpp
|  Autor         : Russell
|  Fecha         : 2025-09-25
|--------------------------------------------------------
|  Tópicos utilizados:
|  - implementation
|  - div3
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
    int cntZeros = 0, contOnesNeg = 0;
    for(int i = 0 ;i < n; i++){
        int x; cin >> x;
        if(x == 0) cntZeros++;
        if(x == -1) contOnesNeg++;
    }
    int ans = 0;
    ans += cntZeros;
    contOnesNeg %= 2;
    ans += contOnesNeg*2;
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