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

#define pb push_back
#define mp make_pair

ll gcd(ll a,ll b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

typedef vector<int> vi;
typedef vector<ll> vll;


class SegmentTree {                              // OOP style
private:
    int n;                                         // n = (int)A.size()
    vll A, st, lazy;                                // the arrays

    int l(int p) { return  p<<1; }                 // go to left child
    int r(int p) { return (p<<1)+1; }              // go to right child

    ll conquer(ll a, ll b) {
        return a^b;                           // RXORQ
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

    ll RXORQ(int p, int L, int R, int i, int j) {   // O(log n)
        if (i > j) return 0;                        // infeasible
        if ((L >= i) && (R <= j)) return st[p];      // found the segment
        int m = (L+R)/2;
        return conquer(RXORQ(l(p), L  , m, i          , min(m, j)),
                        RXORQ(r(p), m+1, R, max(i, m+1), j        ));
    }
public:
    SegmentTree(int sz) : n(sz), A(n), st(4*n), lazy(4*n, -1) {}

    SegmentTree(const vll &initialA) : SegmentTree((int)initialA.size()) {
        A = initialA;
        build(1, 0, n-1);
    }
    ll RXORQ(int i, int j) { return RXORQ(1, 0, n-1, i, j); }
};

void solve(){
    int n,q; cin>>n>>q;
    vll A(n);
    for(ll &x:A) cin >> x;
    SegmentTree ST(A);
    while(q--){
        int a,b; cin>>a>>b;
        a--;b--;
        cout << ST.RXORQ(a,b) << endl;
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