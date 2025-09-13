/*
==========================================================
|  Archivo       : C_Pacer.cpp
|  Autor         : Russell
|  Fecha         : 2025-09-13 10:18
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
    int n,m; cin >> n >> m;
    vector<pii> arr(n+1);
    arr[0] = {0,0};
    for(int e = 1 ;e <= n ; e++){
        int a, b; cin >> a >> b;
        arr[e] = {a,b};
    }
    ll total = 0;
    for(int e = 1;e <= n ; e++){
        auto before = arr[e-1];
        auto current = arr[e];
        // cout << before.first << " " << before.second << " | " << current.first << " " << current.second << endl;
        // continue;
        if( (current.first-before.first)&1){
            if(current.second != before.second) total += abs(current.first - before.first);
            else total += abs(current.first - before.first) - 1;
        }else {
            if(current.second != before.second) total += abs(current.first - before.first) - 1;
            else total += abs(current.first - before.first);
        }
    }
    auto last = arr[n];
    if(last.first < m ) total += (m - last.first);
    cout << total << endl;
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