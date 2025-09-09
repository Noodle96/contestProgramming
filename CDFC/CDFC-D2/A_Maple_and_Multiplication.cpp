/*
==========================================================
|  Archivo       : A_Maple_and_Multiplication.cpp
|  Autor         : Russell
|  Fecha         : 2025-09-08
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Implementación
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
    int a,b;
    cin >> a >> b;
    if(a == b ){
        cout << 0 << endl;
    }else if(a%b == 0 || b%a == 0){
        cout << 1 << endl;
    }else{
        cout << 2 << endl;
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
    while(t-- ){
        solve();
    }
    return 0;
}