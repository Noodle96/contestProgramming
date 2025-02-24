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

ll gcd(ll a,ll b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

class SegmentTree{
    private:
        int n;
        vll A, st, lazy;
        int l(int p){return p<<1;}
        int r(int p){return (p<<1)+1;}

        ll conquer(ll a, ll b){return a+b;}
        
        void propagate(int p, int L, int R){
            if(lazy[p] != 0){
                st[p] += (R-L+1)*lazy[p];
                if(L != R){
                    lazy[l(p)] += lazy[p];
                    lazy[r(p)] += lazy[p];
                }
                lazy[p] = 0;
            }
        }

        void build(int p, int L, int R){
            if(L == R) st[p] = A[L];
            else{
                int m = (L+R)/2;
                build(l(p),L,m);
                build(r(p),m+1,R);
                st[p] = conquer(st[l(p)], st[r(p)]);
            }
        }
        void update(int p, int L, int R, int i, int j, ll val){
            propagate(p, L, R);
            if(i > j) return;
            if(i <= L && j>= R){
                lazy[p] += val;
                propagate(p, L, R);
            }else{
                int m = (L+R)/2;
                update(l(p), L,m,i,min(m,j),val);
                update(r(p),m+1,R,max(i,m+1),j,val);
                st[p] = conquer(st[l(p)],st[r(p)]);
            }
        }
        ll query(int p, int L, int R, int i, int j){
            propagate(p, L, R);
            if(i > j) return 0;
            if(i <= L && j >= R) return st[p];
            int m = (L+R)/2;
            return conquer(
                            query(l(p),L,m,i,min(m,j)),
                            query(r(p),m+1,R,max(i,m+1),j)
                        );
        }

    public:
        SegmentTree(int nz): n(nz), A(nz),st(4*nz), lazy(4*nz,0){}
        SegmentTree(const vll &initialA): SegmentTree((int)initialA.size()){
            A = initialA;
            build(1,0,n-1);
        }
        void update(int i, int j, ll val){
            update(1,0,n-1,i,j,val);
        }
        ll query(int i, int j){
            return query(1,0,n-1,i,j);
        }
};


void solve(){
    int N, q; cin>>N>>q;
    vll A(N);
    for(auto &x:A) cin>>x;
    SegmentTree ST(A);
    while(q--){
        int type; cin>>type;
        if(type == 1){
            int a,b; ll u;
            cin>>a>>b>>u;
            a--,b--;
            ST.update(a,b,u);
        }else{
            int k; cin>>k; k--;
            cout << ST.query(k,k) << endl;
        }
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