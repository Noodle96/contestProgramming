// Enfoque: Encontrar el primer elemento mayor que X en un arreglo.
// Problema: Dado un arreglo de hoteles y un arreglo de clientes, para cada cliente, encontrar el primer hotel que tenga al menos X camas disponibles.
// Solución: Utilizar un Segment Tree para mantener el número de camas disponibles en cada hotel. Para cada cliente, buscar el primer hotel que
// tenga al menos X camas disponibles y restar X camas de ese hotel.
// Complejidad: O(n) para construir el Segment Tree y O(m log n) para responder a las consultas, donde n es el número de hoteles y m es el número de clientes.
// TIP: FINDING THE FIRST GREATER ELEMENT THAN X
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

typedef vector<ll> vll;

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
        ll conquer(ll a, ll b){return max(a,b);}
        void build(int p, int L, int R){
            if(L==R) st[p] = A[L];
            else{
                int m = (L + R)/2;
                build(l(p),L,m);
                build(r(p), m+1,R);
                st[p] = conquer(st[l(p)],st[r(p)]);
            }
        }
        void propagate(int p, int L, int R){
            if(lazy[p] != 0){
                st[p] += lazy[p];   
                if(L != R){
                    lazy[l(p)] += lazy[p];
                    lazy[r(p)] += lazy[p];
                }else{
                    A[L] += lazy[p]; 
                }
                lazy[p] = 0;
            }
        }
        void update(int p, int L, int R, int i, int j, ll val){
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
                st[p] = conquer(st[l(p)], st[r(p)]);
            }
        }
        int query(int p, int L, int R, ll X){
            propagate(p, L, R);
            if(st[p] >= X){
                if(L == R) return L;
                int m = (L+R)/2;
                if(st[l(p)] >= X) return query(l(p),L,m,X);
                return query(r(p),m+1,R,X);
            }
            return -1;
        }

    public:
        SegmentTree(int nz): n(nz), A(nz), st(4*nz), lazy(4*nz,0){}
        SegmentTree(vll &initialA): SegmentTree((int)initialA.size()){
            A = initialA;
            build(1,0,n-1);
        }
        void update(int i, int j, ll val) { update(1, 0, n-1, i, j, val); }
        int query(ll X){return query(1,0,n-1,X);}
        void print(){
            cout << "print st" << endl;
            for(int e = 0 ; e < 4*n; e++){
                cout << setw(4) << e;
            }cout << endl;
            for(int e = 0; e < 4*n ; e++){
                cout << setw(4) << st[e];
            }cout << endl<< endl;
        }

};


void solve(){
    int n,m; cin>>n>>m;
    vll A(n);
    for(ll &x:A) cin >> x;
    SegmentTree ST(A);
    while(m--){
        // ST.print();
        ll x; cin >> x;
        int pos = ST.query(x);
        if(pos != -1){
            cout << pos +1 << " ";
            ST.update(pos,pos,-x);
        }else{
            cout << 0 << " ";
        }
    }cout << endl;
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