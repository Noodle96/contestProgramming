/*
==========================================================
|  Archivo       : Lastone.cpp
|  Autor         : Russell
|  Fecha         : 2025-07-26 16:29
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Implementation
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
    int h1,d1,t1, h2, d2, t2;
    cin >> h1 >> d1 >> t1 >> h2 >> d2 >> t2;
    int total1, total2;
    total1 = (( h2%d1 == 0 ? h2/d1 : h2/d1 + 1) - 1 ) * t1;
    total2 = (( h1%d2 == 0 ? h1/d2 : h1/d2 + 1) - 1 ) * t2;
    // cout << total1 << " " << total2 << endl;
    if(total1 < total2){
        cout << "player one" << endl;
    }else if(total1 > total2){  
        cout << "player two" << endl;
    }else{
        cout << "draw" << endl;
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