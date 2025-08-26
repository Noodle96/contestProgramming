/*
==========================================================
|  Archivo       : B_Cow_and_Friend.cpp
|  Autor         : Russell
|  Fecha         : 2025-08-26 17:23
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Geometry Computational
|  - *1300
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
    int n,x;
    cin >> n >> x;
    set<int> a;
    int maximo = -1;
    for(int e = 0 ;e <n ; e++){
        int x_i;
        cin >> x_i;
        a.insert(x_i);
        maximo = max(maximo,x_i);
    }
    if(a.count(x)){
        cout << 1 << endl;
        return;
    }
    cout << max(2,x/maximo + (x%maximo != 0)) << endl;
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