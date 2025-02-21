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

typedef vector<int> vi;
typedef vector<char> vc;

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

int I,J;
char ch;

class SegmentTree {                              // OOP style
private:
    int n;                                         // n = (int)A.size()
    vi A;
    vc st, lazy;                                // the arrays

    int l(int p) { return  p<<1; }                 // go to left child
    int r(int p) { return (p<<1)+1; }              // go to right child

    char conquer(char a, char b) {
        if(a == '0' || b == '0') return '0';                       // corner case
        if(a=='+' && b=='+') return '+';
        if(a=='-' && b=='-') return '+';
        if(a=='+' && b=='-') return '-';
        if(a=='-' && b=='+') return '-';
        return '*'; // never
    }

    void build(int p, int L, int R) {              // O(n)
        if (L == R){
            st[p] = (A[L]>0?'+':(A[L]<0?'-':'0'));
            // cout << "st[" << p << "] = "<<st[p] << endl;
        }
        else {
            int m = (L+R)/2;
            build(l(p), L  , m);
            build(r(p), m+1, R);
            st[p] = conquer(st[l(p)], st[r(p)]);
            // cout << "st[" << p << "] = "<<st[p] << endl;
        }
    }

    void propagate(int p, int L, int R) {
        if (lazy[p] != 'x') {    
            // has a lazy flag
            st[p] = lazy[p];                           // [L..R] has same value
            if (L != R){                               // not a leaf
                lazy[l(p)] = lazy[r(p)] = lazy[p];       // propagate downwards
            }
            else {                                      // L == R, a single index
                A[L] = lazy[p];                          // time to update this
            }
            lazy[p] = 'x';                              // erase lazy flag
        }
    }

    char Query(int p, int L, int R, int i, int j) {   // O(log n)
        propagate(p, L, R);                          // lazy propagation
        if (i > j) return '+';                        // infeasible
        if ((L >= i) && (R <= j)) return st[p];      // found the segment
        int m = (L+R)/2;
        return conquer(Query(l(p), L  , m, i          , min(m, j)),
                    Query(r(p), m+1, R, max(i, m+1), j        ));
    }

    void update(int p, int L, int R, int i, int j, int val) { // O(log n)
        propagate(p, L, R);                          // lazy propagation
        if (i > j) return;
        if ((L >= i) && (R <= j)) {                  // found the segment
            lazy[p] = (val>0?'+':(val<0?'-':'0'));
            // cout << "lazy[" <<p << "] = " << lazy[p] << endl;                          // update this
            propagate(p, L, R);                        // lazy propagation
        }
        else {
            int m = (L+R)/2;
            update(l(p), L  , m, i          , min(m, j), val);
            update(r(p), m+1, R, max(i, m+1), j        , val);
            // char lsubtree = (lazy[l(p)] != 'x') ? lazy[l(p)] : st[l(p)];
            // char rsubtree = (lazy[r(p)] != 'x') ? lazy[r(p)] : st[r(p)];
            // cout << "in update" << endl;
            // cout << "l(" << p << ") = " << st[l(p)] << " r(" << p << ") = " << st[r(p)] << endl;
            st[p] = conquer(st[l(p)], st[r(p)]);
        }
    }

    public:
    SegmentTree(int sz) : n(sz), A(n), st(4*n), lazy(4*n, 'x') {}

    SegmentTree(const vi &initialA) : SegmentTree((int)initialA.size()) {
        A = initialA;
        build(1, 0, n-1);
    }

    void update(int i, int j, int val) { update(1, 0, n-1, i, j, val); }

    char Query(int i, int j) { return Query(1, 0, n-1, i, j); }

    void printST(){
        for(int e = 0 ; e < 8; e++){
            cout << "st[" << e << "] = "<<st[e] << "\n";
        }cout << endl;
    }
};


void solve(){
    int N,m;
    while(cin>>N>>m){
        vector<int> A(N);
        for(int e = 0 ; e < N; e++)cin>>A[e];
        SegmentTree ST(A);
        // ST.printST();

        for(int e = 0 ; e < m; e++){
            cin>>ch>>I>>J;
            I--;
            if(ch == 'C'){
                // cout << "Caso C:" << endl;
                ST.update(I,I,J);
                // ST.printST();
            }else{
                J--;
                cout << ST.Query(I,J);
            }
        }cout << endl;
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