/*
==========================================================
|  Archivo       : Memories.cpp
|  Autor         : Russell
|  Fecha         : 2025-04-29 09:51
|--------------------------------------------------------
|  Tópicos utilizados:
|  - BinarySearch
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
vector<ll> section;
int n;
ll k;
bool puede(ll m){
    ll viajes_usados = 0;
    for(auto section_i: section){
        viajes_usados += (section_i + m - 1 )/m; // esto es similar al ceil(section_i/m)
    }
    return viajes_usados <= k;
}

void solve(){
    cin>>n;
    cin>>k;
    section.resize(n);
    for(auto &e:section) cin>>e;
    ll l = 1, r = 1LL<<60;
    // cout << "l: " << l << " r: " << r << "\n";

    ll ans = r;
    while(l <= r){
        ll m = (l+r) >> 1;
        if(puede(m)){
            r = m-1; // tratamos de buscar un s menor
            ans = m; // m es una solucion valida por el momento
        }else{
            l =  m+1;
        }
    }
    cout << ans << "\n";
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