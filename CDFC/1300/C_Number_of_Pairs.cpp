/*
==========================================================
|  Archivo       : C_Number_of_Pairs.cpp
|  Autor         : Russell
|  Fecha         : 2025-04-25 08:56
|--------------------------------------------------------
|  Tópicos utilizados:
|  - BinarySearch
|  - TwoPointers
|  - Sorting
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
    int n,l,r;
    cin>>n>>l>>r;
    vector<ll> a(n);
    for(auto &a_i: a) cin>>a_i;
    sort(all(a));

    vector<ll> lessEqual(n), greaterEqual(n);
    for(auto e = 0; e < n; e++){
        lessEqual[e] = r-a[e];
        greaterEqual[e] = l-a[e];
    }
    // cout << "lessEqual: \n";
    // for(auto e = 0; e < n; e++){
    //     cout << lessEqual[e] << " ";
    // }
    // cout << endl;
    // cout << "greaterEqual: \n";
    // for(auto e = 0; e < n; e++){
    //     cout << greaterEqual[e] << " ";
    // }
    // cout << endl;
    ll ans = 0;
    for(auto l = 0; l < n-1; l++){
        auto lessEqualCount = upper_bound(a.begin() + l+1, a.begin() + n, lessEqual[l]);
        auto indexLess = lessEqualCount - (a.begin() + l + 1) - 1;
        // cout << indexLess << " ";
        // auto totalLess = lessEqualCount - (a.begin() + l+1);
        auto greaterEqualCount = lower_bound(a.begin() + l+1, a.begin()+n ,greaterEqual[l]);
        auto indexGreater = greaterEqualCount - (a.begin() + l + 1);
        // auto pos = greaterEqualCount - (a.begin() + l +1);
        // auto totalGreater = (n - (l+1)) - pos;
        // ans += min(totalLess, totalGreater);
        // cout << indexGreater << endl;
        if(indexLess >= indexGreater){
            ans += (indexLess - indexGreater + 1);
        }
    }
    cout << ans << endl;

}
void solve2(){
    vector<ll> a = {1,2,3,3,5};
    int l = 0, r = 4;
    auto upperBoundSegment = upper_bound(a.begin() +l , a.begin() + r +1, 3);
    auto upperIndexSegment = upperBoundSegment - (a.begin()+l);
    // cout  << upperIndexSegment << endl;
    // auto upperBound = upper_bound(a.begin()+3, a.end(), 3);
    // auto upperIndex = upperBound - a.begin();
    // cout << "Upper Bound: " << upperIndex << endl;
    auto lowerBoundSegment = lower_bound(a.begin() +l , a.begin() + r +1, 4);
    auto lowerIndexSegment = lowerBoundSegment - (a.begin()+l);
    cout  << lowerIndexSegment << endl;
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
    // solve2();
    return 0;
}