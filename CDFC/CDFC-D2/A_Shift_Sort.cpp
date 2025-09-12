/*
==========================================================
|  Archivo       : A.cpp
|  Autor         : Russell
|  Fecha         : 2025-09-09
|--------------------------------------------------------
|  Tópicos utilizados:
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

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    // contar Zeros
    int contZeros = 0;
    for(int e = 0 ;e < n ;  e++){
        if(s[e] == '0') contZeros++;
    }
    int contOnes = 0;
    for(int e = 0 ; e < contZeros; e++){
        if(s[e] == '1' ) contOnes++;
    }
    cout << contOnes << endl;
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