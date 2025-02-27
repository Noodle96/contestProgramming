#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define msg(str,str2) cout << str << str2<< endl
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

class SegmentTree {                                     // OOP style
    private:
        int n;                                         // n = (int)A.size()
        vll A, st, lazy;                                // the arrays

        int l(int p) { return  p<<1; }                 // go to left child
        int r(int p) { return (p<<1)+1; }              // go to right child

        ll conquer(ll a, ll b) {
            if (a == INF) return b;                       // corner case
            if (b == INF) return a;
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
            if (lazy[p] != 0) {                         // has a lazy flag
                st[p] += lazy[p];                           // [L..R] has same value
                if (L != R){                            // not a leaf
                    lazy[l(p)] += lazy[p];                    // propagate downwards
                    lazy[r(p)] += lazy[p];
                }                                
                else                                       // L == R, a single index
                    A[L] += lazy[p];                          // time to update this
                lazy[p] = 0;                              // erase lazy flag
            }
        }

        ll RMQ(int p, int L, int R, int i, int j) {   // O(log n)
            propagate(p, L, R);                          // lazy propagation
            if (i > j) return INF;                        // infeasible
            if ((L >= i) && (R <= j)) return st[p];      // found the segment
            int m = (L+R)/2;
            return conquer(RMQ(l(p), L  , m, i          , min(m, j)),
                            RMQ(r(p), m+1, R, max(i, m+1), j        ));
        }

        void update(int p, int L, int R, int i, int j, ll val) { // O(log n)
            propagate(p, L, R);                          // lazy propagation
            if (i > j) return;
            if ((L >= i) && (R <= j)) {                  // found the segment
                lazy[p] += val;                             // update this
                propagate(p, L, R);                        // lazy propagation
            }
            else {
                int m = (L+R)/2;
                update(l(p), L  , m, i          , min(m, j), val);
                update(r(p), m+1, R, max(i, m+1), j        , val);
                st[p] = conquer(st[l(p)], st[r(p)]);
            }
        }

public:
    SegmentTree(int sz) : n(sz), A(n), st(4*n), lazy(4*n, 0) {}
    
    SegmentTree(const vll &initialA) : SegmentTree((int)initialA.size()) {
        A = initialA;
        build(1, 0, n-1);
    }
    
    void update(int i, int j, ll val) { update(1, 0, n-1, i, j, val); }
    
    ll RMQ(int i, int j) { return RMQ(1, 0, n-1, i, j); }

    void print(){
        int limit = 6;
        for(int e = 0 ; e < limit; e++){
            cout << setw(4) << e;
        }cout << endl;

        for(int e = 0 ; e < limit; e++){
            cout << setw(4) << st[e];
        }cout << endl;

        for(int e = 0 ; e < limit; e++){
            cout << setw(4) << lazy[e];
        }cout << endl;
    }
};



void solve(){
    int n; cin>>n;
    vll A(n);
    for(auto &x:A) cin >> x;
    SegmentTree st(A);
    // cout << "inicial:  " << endl;
    // st.print();
    int q; cin>>q;
    string s;
    cin.ignore();
    while(q--){
        getline(cin,s);
        stringstream ss(s);
        vector<ll> temp;
        while(ss>>s){
            temp.pb(stoll(s));
        }
        if(temp.size() == 3){
            if(temp[0] > temp[1]){
                st.update(temp[0],n-1,temp[2]);
                st.update(0,temp[1],temp[2]);
            }else{
                st.update(temp[0],temp[1],temp[2]);
            }
        }else{
            if(temp[0] > temp[1]){
                cout << min(st.RMQ(temp[0],n-1),st.RMQ(0,temp[1])) << endl;
            }else{
                cout << st.RMQ(temp[0],temp[1]) << endl;
            }
        }
        // cout << "\nejecucion: " << endl;
        // st.print();
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
// -1 0 0