/*
==========================================================
|  Archivo       : A_Letter_Home.cpp
|  Autor         : Russell
|  Fecha         : 2025-06-17 10:31
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
    int n,s;
    cin>>n>>s;
    vector<int> a(n);
    for(int e = 0 ; e < n; e++){
        cin>>a[e];
    }
    auto minimo = *min_element(all(a));
    auto maximo = *max_element(all(a));
    if(s > maximo){
        cout << s - minimo << endl;
        return;
    }
    if(s < minimo){
        cout << maximo - s << endl;
        return;
    }

    int ans;
    if(s - minimo <= maximo - s){
        ans = s - minimo;
        ans *=2;
        ans += (maximo - s);
    }else{
        ans = maximo - s;
        ans *= 2;
        ans += (s - minimo);
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
    int t; cin>>t;
    while( t--) solve();
    return 0;
}