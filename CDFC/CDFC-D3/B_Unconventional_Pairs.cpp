/*
==========================================================
|  Archivo       : B_Unconventional_Pairs.cpp
|  Autor         : Russell
|  Fecha         : 2025-09-25 10:25
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

const int INF = 1e9;

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
    vector<int> a(n);
    for(int i = 0 ;i < n; i++) cin >> a[i];
    sort(all(a), greater<int>());

    int maximo = -INF;
    for(int i = 0 ; i < n - 1; i+=2){
        maximo = max(maximo, abs(a[i]- a[i+1]));
    }
    cout << maximo << endl;
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