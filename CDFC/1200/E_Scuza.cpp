/*
==========================================================
|  Archivo       : E_Scuza.cpp
|  Autor         : Russell
|  Fecha         : 2025-05-03 14:10
|--------------------------------------------------------
|  Tópicos utilizados:
|  - BinarySearch
|  - Greedy
|  - *1200
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
    int n,q;
    cin>>n>>q;
    vector<ll> h(n);
    for(int e = 0 ; e < n; e++) cin>>h[e];
    deque<ll> prefixSum(n);
    prefixSum[0] = h[0];
    for(int e = 1 ; e < n; e++) prefixSum[e] = prefixSum[e-1] + h[e];
    prefixSum.push_front(0);
    vector<ll> maxh(n);
    maxh[0] = h[0];
    for(int e = 1 ;e < n ;e++) maxh[e] = max(maxh[e-1],h[e]);
    while(q--){
        int k; cin>>k;
        auto it_upperBound = upper_bound(all(maxh),k);
        int index = it_upperBound - maxh.begin();
        // cout << index << " ";
        cout << prefixSum[index] << " ";
    }
    cout << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t; cin>>t;
    while(t--) solve();
    return 0;
}

// 11 14 3 10 6 11 3 14 3 7 14 2 10 5 4
// 100 46 29 82 70 8 28 28 119 100