/*
==========================================================
|  Archivo       : C_Equalize.cpp
|  Autor         : Russell
|  Fecha         : 2025-06-09 13:20
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
    int n; cin>>n;
    string a,b; cin>>a>>b;
    int i = 0, costo = 0;
    while(i < n){
        if(a[i] == b[i])i++;
        else if(i+1 < n && a[i] != b[i] &&
                a[i+1] != b[i+1] && a[i] != a[i+1]){
            costo += 1;
            i +=2;
        }else{
            costo += 1;
            i++;
        }
    }
    cout << costo << '\n';
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