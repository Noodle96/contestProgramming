/*
==========================================================
|  Archivo       : C_Rotation_Matching.cpp
|  Autor         : Russell
|  Fecha         : 2025-10-04 11:43
|--------------------------------------------------------
|  Tópicos utilizados:
|  - training
|  - *1400
|  - data structures
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
struct func{
    bool operator()(const pii &a, const pii &b) const{
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    }
};

void solve(){
    int n; cin >> n;
    set<pii> a;
    for(int i = 1 ;i <= n ; i++){
        int x; cin >> x;
        a.insert({x,i});
    }
    set<pii> b;
    for(int i = 1 ;i <= n ; i++){
        int x; cin >> x;
        b.insert({x,i});
    }
    map<int, int> ans;
    for(auto [val,idx1]: a){
        auto it = b.lower_bound({val, INT_MIN});
        // esta garantizado que val esta en la permutacion b
        int idx2 = it->second;
        if(idx2 >= idx1) ans[idx2-idx1]++;
        else{
            ans[n - (idx1 - idx2)]++;
        } 
    }
    int ansMax = INT_MIN;
    for(auto [k,v]: ans){
        ansMax = max(ansMax, v);
    }
    cout << ansMax << endl;
}  
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;
    //cin >> t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}