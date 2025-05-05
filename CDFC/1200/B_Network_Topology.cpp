/*
==========================================================
|  Archivo       : B_Network_Topology.cpp
|  Autor         : Russell
|  Fecha         : 2025-05-05 16:07
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Graph
|  - Implementation
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

const ll INF = 1e18;

ll gcd(ll a,ll b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

vector<ll> inDegree, outDegree;
void solve(){
    int n,m;
    cin>>n>>m;
    inDegree.assign(n,0);
    outDegree.assign(n,0);
    while(m--){
        int u,v;
        cin>>u>>v;
        u--;v--;
        inDegree[v]++; outDegree[v]++;
        inDegree[u]++; outDegree[u]++;
    }
    map<ll,ll> totalInDegree;
    for(int e = 0 ; e < n; e++){
        totalInDegree[inDegree[e]]++;
    }
    map<ll,ll> totalOutDegree;
    for(int e = 0 ; e < n; e++){
        totalOutDegree[outDegree[e]]++;
    }
    // for(auto in_i: totalInDegree){
    //     cout << in_i.first << " " << in_i.second << endl;
    // }
    // cout << endl;
    // for(auto out_i: totalOutDegree){
    //     cout << out_i.first << " " << out_i.second << endl;
    // }
    // return;
    auto twoIn = totalInDegree.find(2);
    auto twoOut = totalOutDegree.find(2);
    ll test = 2;
    if(twoIn != totalInDegree.end() && twoOut != totalOutDegree.end()){
        if(twoIn->second == twoOut->second && twoIn->second == n ){
            cout << "ring topology" << endl;
            return;
        }
    }
    auto oneIn = totalInDegree.find(1);
    auto oneOut = totalOutDegree.find(1);
    if(oneIn != totalInDegree.end() && oneOut != totalOutDegree.end() &&
        twoIn != totalInDegree.end() && twoOut != totalOutDegree.end()){
        if(oneIn->second == oneOut->second && oneIn->second == 2 && twoIn->second == twoOut->second && twoIn->second == n-2){
            cout << "bus topology" << endl;
            return;
        }

    }
    auto nMinusOneIn = totalInDegree.find(n-1);
    auto nMinusOneOut = totalOutDegree.find(n-1); 
    if(oneIn != totalInDegree.end() && oneOut != totalOutDegree.end() &&
        nMinusOneIn != totalInDegree.end() && nMinusOneOut != totalOutDegree.end()){
        if(oneIn->second == oneOut->second && oneIn->second == n-1 && 
            nMinusOneIn->second == nMinusOneOut->second && nMinusOneIn->second == 1
        ){
            cout << "star topology" << endl;
            return;
        }
    }
    cout << "unknown topology" << endl;

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