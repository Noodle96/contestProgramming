/*
==========================================================
|  Archivo       : D_Kevin_and_Numbers.cpp
|  Autor         : Russell
|  Fecha         : 2025-10-03 18:54
|--------------------------------------------------------
|  Tópicos utilizados:
|  - training
|  - *1600
|  - data structures
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
    int n, m; cin >> n >> m;
    multiset<int> a,b;
    for(int i = 0 ;i < n ; i++){
        int x; cin >> x;
        a.insert(x);
    }
    for(int i = 0 ;i < m ; i++){
        int x; cin >> x;
        b.insert(x);
    }
    // Podemos simular la inversa, es decir en b podemos decir que este puede
    // llegar de dos formas, v/2 p v+1/2.
    while(!b.empty() && b.size() <= a.size()){
        auto first = *b.begin();
        b.erase(b.begin());
        auto it = a.find(first);
        if(it != a.end()){
            a.erase(it);
        }else{
            // Si no está en a, podemos agregar sus posibles predecesores
            b.insert(first/2);
            b.insert((first+1)/2);
        }
    }
    if(a.empty() && b.empty()){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }   
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