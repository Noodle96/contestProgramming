/*
==========================================================
|  Archivo       : Injured.cpp
|  Autor         : Russell
|  Fecha         : 2025-09-06 13:26
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Data Structures
|  - Brute Force
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
    map<string, int> mapa;
    for(int e = 0 ; e< n; e++){
        string s; cin >> s;
        mapa[s]++;
    }
    // preprocesamiento
    map<string, int> mapaConcatenado;
    for(auto x: mapa){
        for(auto y: mapa){
            string concatenado = x.first + y.first;
            mapaConcatenado[concatenado] += 1;
        }
    }
    int m; cin >> m;
    while(m--){
        string s; cin >> s;
        if(mapa.find(s) != mapa.end()){
            // si le encontro
            cout << 1 << endl;
        }else if(mapaConcatenado.find(s) != mapaConcatenado.end()){
            cout << 2 << endl;
        } else {
            cout << 0 << endl;
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