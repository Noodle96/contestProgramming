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
using vi = vector<int>;
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

class SegmentTree {
    private:
        int n;
        vll A, st, lazy;


        int l(int p) { return p << 1; }   
        int r(int p) { return (p << 1) + 1; }    

        ll conquer(ll a, ll b) { return a + b; } // Ahora hacemos la suma

        void build(int p, int L, int R) { // Construcción en O(n)
            if (L == R)
                st[p] = A[L]; 
            else {
                int m = (L + R) / 2;
                build(l(p), L, m);
                build(r(p), m+1, R);
                st[p] = conquer(st[l(p)], st[r(p)]);
            }
        }

        void propagate(int p, int L, int R) {
            if (lazy[p] != 0) { // Si hay un valor pendiente por propagar
                st[p] = ((ll)R - (ll)L + 1) * lazy[p]; // Sumar el valor al rango completo
                if (L != R) { // Si no es hoja, propagar a los hijos
                    lazy[l(p)] += lazy[p];
                    lazy[r(p)] += lazy[p];
                }
                lazy[p] = 0; // Limpiar el nodo actual
            }
        }

        ll RSQ(int p, int L, int R, int i, int j) {
            propagate(p, L, R); // Aplicar Lazy Propagation
            if (i > j) return 0; // Si el rango es inválido
            if (L >= i && R <= j) return st[p]; // Si el segmento está completamente dentro del rango

            int m = (L + R) / 2;
            return conquer(RSQ(l(p), L, m, i, min(m, j)), 
                            RSQ(r(p), m+1, R, max(i, m+1), j));
        }

        void update(int p, int L, int R, int i, int j, ll val) {
            propagate(p, L, R); // Aplicar Lazy Propagation
            if (i > j) return;
            if (L >= i && R <= j) { // Si el segmento está completamente dentro del rango
                lazy[p] = val; // Marcar para actualización diferida
                propagate(p, L, R); // Aplicar la actualización de inmediato
            }
            else {
                int m = (L + R) / 2;
                update(l(p), L, m, i, min(m, j), val);
                update(r(p), m+1, R, max(i, m+1), j, val);
                st[p] = conquer(st[l(p)], st[r(p)]); // Recalcular el nodo padre
            }
        }

    public:
        SegmentTree(int sz) : n(sz), A(n), st(4*n), lazy(4*n, 0) {}

        SegmentTree(const vll &initialA) : SegmentTree((int)initialA.size()) {
            A = initialA;
            build(1, 0, n-1);
        }

        void update(int i, int j, ll val) { update(1, 0, n-1, i, j, val); }

        ll RSQ(int i, int j) { return RSQ(1, 0, n-1, i, j); }
        void printST(){
            cout << "print ST" << endl;
            for(int e = 0 ; e < 4*n; e++){
                cout << st[e] << " ";
            }cout << endl;
        }
};

int type;

void solve(){
    int N,q;
    cin >> N >> q;
    vll A(N);
    for(ll &x:A) cin >> x;
    SegmentTree ST(A);
    while(q--){
        cin>>type;
        if(type == 1){
            int a;
            ll b;
            cin>>a>>b;
            a--;
            ST.update(a,a,b);
            // ST.printST();
        }else{
            int a,b; cin>>a>>b;
            a--;b--;
            cout << ST.RSQ(a,b) << endl;
            // ST.printST();
        }

    }
}

void solve2(){
    int a = 10;
    ll b = 2e9;
    cout << a*b << endl;
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