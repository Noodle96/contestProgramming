/*
==========================================================
|  Archivo       : C_rango.cpp
|  Autor         : Russell
|  Fecha         : 2025-06-28 12:23
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
int temp;
void solve(){
    int n; cin>>n;
    vector<int> v(n);
    for(int e = 0 ;e < n ; e++){
        int total = 0;
        for(int j = 0 ; j < 4; j++){
            cin>>temp;
            total += temp;
        }
        v[e] = total;
    }
    int tomas = v[0];
    sort(all(v), greater<int>());
    for(int e = 0 ; e < n ;e++){
        if(v[e] == tomas){
            cout << e + 1 << endl;
            return;
        }
    }
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