/*
==========================================================
|  Archivo       : sparseTable.cpp
|  Autor         : Russell
|  Fecha         : 2025-08-13 21:28
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Sparse Table
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
const int MAX = 1e7 +7;
const int LN = 23;
int a[MAX];
int st[MAX][LN];
int n;

void build(){
    for(int i = 1; i <=n ; i++)
        st[i][0] = a[i];
    for(int j = 1; (1 << j) <= n; j++)
        for(int i = 1; i + (1 << j) -1 <= n; i++)
            st[i][j] = min(st[i][j-1], st[i + (1 << (j-1))][j-1]);
}
int query(int l, int r){
    if(l > r) return INT_MAX;
    int len = log2(r - l + 1);
    return min(st[l][len], st[r - (1 << len) + 1][len]);
}

void solve(){
    cin>>n;
    for(int e = 0 ;e < n ; e++) cin>>a[e+1];
    build();
    int q; cin>>q;
    while(q--){
        int l, r; cin>>l>>r;
        cout<<query(l, r)<<"\n";
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