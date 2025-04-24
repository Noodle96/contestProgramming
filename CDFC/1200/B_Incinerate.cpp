/*
==========================================================
|  Archivo       : B_Incinerate.cpp
|  Autor         : Russell
|  Fecha         : 2025-04-24 13:20
|--------------------------------------------------------
|  Tópicos utilizados:
|  - DataStructure
|  - BinarySearch
|  - Sorting
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


class SegmentTree {                              // OOP style
    private:
        int n;                                         // n = (int)A.size()
        vll A, st, lazy;                                // the arrays
    
        int l(int p) { return  p<<1; }                 // go to left child
        int r(int p) { return (p<<1)+1; }              // go to right child
    
        ll conquer(ll a, ll b) {
            if (a == -1) return b;                       // corner case
            if (b == -1) return a;
            return min(a, b);                            // RMQ
        }
    
        void build(int p, int L, int R) {              // O(n)
            if (L == R)
                st[p] = A[L];                              // base case
            else {
                int m = (L+R)/2;
                build(l(p), L  , m);
                build(r(p), m+1, R);
                st[p] = conquer(st[l(p)], st[r(p)]);
            }
        }
    
        void propagate(int p, int L, int R) {
            if (lazy[p] != -1) {                         // has a lazy flag
                st[p] = lazy[p];                           // [L..R] has same value
                if (L != R)                                // not a leaf
                    lazy[l(p)] = lazy[r(p)] = lazy[p];       // propagate downwards
                else                                       // L == R, a single index
                    A[L] = lazy[p];                          // time to update this
                lazy[p] = -1;                              // erase lazy flag
            }
        }
    
        ll RMQ(int p, int L, int R, int i, int j) {   // O(log n)
            propagate(p, L, R);                          // lazy propagation
            if (i > j) return -1;                        // infeasible
            if ((L >= i) && (R <= j)) return st[p];      // found the segment
            int m = (L+R)/2;
            return conquer(RMQ(l(p), L  , m, i          , min(m, j)),
                            RMQ(r(p), m+1, R, max(i, m+1), j        ));
        }
    
        void update(int p, int L, int R, int i, int j, ll val) { // O(log n)
            propagate(p, L, R);                          // lazy propagation
            if (i > j) return;
            if ((L >= i) && (R <= j)) {                  // found the segment
                lazy[p] = val;                             // update this
                propagate(p, L, R);                        // lazy propagation
            }
            else {
                int m = (L+R)/2;
                update(l(p), L  , m, i          , min(m, j), val);
                update(r(p), m+1, R, max(i, m+1), j        , val);
                ll lsubtree = (lazy[l(p)] != -1) ? lazy[l(p)] : st[l(p)];
                ll rsubtree = (lazy[r(p)] != -1) ? lazy[r(p)] : st[r(p)];
                st[p] = conquer(lsubtree, rsubtree);
            }
        }
    public:
        SegmentTree(int sz) : n(sz), A(n), st(4*n), lazy(4*n, -1) {}
    
        SegmentTree(const vll &initialA) : SegmentTree((int)initialA.size()) {
        A = initialA;
        build(1, 0, n-1);
        }
    
        void update(int i, int j, ll val) { update(1, 0, n-1, i, j, val); }
    
        ll RMQ(int i, int j) { return RMQ(1, 0, n-1, i, j); }
};

void solve(){
    int n,k; cin>>n>>k;
    vector< pair<ll, ll>> h_p(n);
    for(int e = 0 ; e < n; e++) cin>>h_p[e].first;
    for(int e = 0 ; e < n; e++) cin>>h_p[e].second;
    sort(all(h_p));
    vector<ll> h(n);
    for(int e = 0 ; e < n; e++){
        h[e] = h_p[e].first;
    }
    vector<ll> p(n);
    for(int e = 0 ; e < n; e++){
        p[e] = h_p[e].second;
    }
    SegmentTree st(p);

    // for(int e = 0 ; e <n; e++){
    //     cout << h_p[e].first << " " << h_p[e].second << endl;
    // }
    ll total = 0;
    total +=k;
    ll restantes = 0;
    int pos = 0;
    int test = 0;
    int minimo;
    while(pos < n){
        test++;
        auto up = upper_bound(all(h_p), make_pair(total, INF), 
            [](const pair<ll, ll>& a, const pair<ll, ll>& b){
                return a.first < b.first;
            });
        pos = up - h_p.begin();
        restantes = n -pos;
        minimo = st.RMQ(pos, n-1);
        k -= minimo;
        total += k;
        // cout << "pos: " << pos << " restante:  " << restantes<< " min: " << minimo 
        //         <<" k: " << k << " total: " << total<< endl;
        if(k <= 0) break;
    }
    // cout << "pos: " << pos << " restante:  " << restantes<< " min: " << minimo 
    //             <<" k: " << k << " total: " << total<< endl;
    if(pos == n){
        cout  << "YES" << endl;
    }else{
        cout << "NO"  << endl;
    }
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