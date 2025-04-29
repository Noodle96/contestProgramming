/*
==========================================================
|  Archivo       : D_Pair_of_Topics.cpp
|  Autor         : Russell
|  Fecha         : 2025-04-28 18:57
|--------------------------------------------------------
|  Tópicos utilizados:
|  - DataStructures: Vector<pair<ll,ll>>
|  - Sorting
|  - BinarySearch
|  - TwoPointers
|  - *1400
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

/*
    Tenemos
    A = [a1, a2, a3, ..., an]
    B = [b1, b2, b3, ..., bm]
    Luego,
         a1 + a2 > b1 + b2
         a1 - b1 > b2 -a2
    Luego,
        B-A = [b1-a1, b2-a2, b3-a3, ..., bm-an]
        A-B = [a1-b1, a2-b2, a3-b3, ..., an-bn]
    Luego, sort B-A,
    Luego para 0 <= i < n:
        Cuantos elementos estrictamente menores que ai-bi existen bi-ai?
        Hit: Binary Search
*/

void solve(){
    int n; cin>>n;
    vector<ll> a(n), b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    vector<pll> BmA_AmB;
    for(int e = 0 ;e < n ; e++) BmA_AmB.emplace_back(b[e]-a[e], a[e]-b[e]);
    sort(all(BmA_AmB), [](pll a, pll b){
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
    });
    int r = n;
    ll total = 0;
    for(int l = 0 ;l < n-1 ; l++){
        ll target = BmA_AmB[l].second;
        auto it = lower_bound(BmA_AmB.begin() + l + 1, BmA_AmB.begin() + r , make_pair(target, -INF));
        total += ( it -(BmA_AmB.begin() + l + 1));
    }
    cout << total << endl;
}
void solve2(){
    vector<int> a = {1, 2, 3, 4, 5};

    int l = 2, r = 5;
    auto lower = lower_bound(a.begin() + l, a.begin() + r, 70 );
    cout << lower - (a.begin() + l) << endl;
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