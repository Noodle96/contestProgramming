/*
==========================================================
|  Archivo       : D_Binary_Cut.cpp
|  Autor         : Russell
|  Fecha         : 2025-08-28 18:38
|--------------------------------------------------------
|  Tópicos utilizados:
|  - *1100
|  - implementation
|  - string
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
bool zeroOne(string str){
    int n = (int)str.size();
    for(int e = 0 ;e < n-1 ; e++){
        if(str[e] == '0' && str[e+1] == '1') return true;
    }
    return false;
}

void solve(){
    string str; cin >> str;
    int n = (int)str.size();
    bool findBinary = true;
    int cut = 0;
    for(int e = 0 ; e < n  - 1; e++){
        if(str[e] != str[e+1]) cut++;
    }
    int pieces = ++cut;
    if(zeroOne(str)){
        cout << pieces -1 << endl;
    }else{
        cout << pieces << endl;
    }
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