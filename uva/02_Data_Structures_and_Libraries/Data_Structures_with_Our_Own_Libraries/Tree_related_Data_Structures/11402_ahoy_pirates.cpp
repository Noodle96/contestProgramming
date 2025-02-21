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
    vi A, st, lazy;

    int l(int p) { return p << 1; }      // Hijo izquierdo
    int r(int p) { return (p << 1) + 1; } // Hijo derecho

    void build(int p, int L, int R) {
        if (L == R) {
            st[p] = A[L]; // Inicializa con el valor del array original
        } else {
            int m = (L + R) / 2;
            build(l(p), L, m);
            build(r(p), m + 1, R);
            st[p] = st[l(p)] + st[r(p)];
        }
    }

    void propagate(int p, int L, int R) {
        if (lazy[p] == -1) return; // No hay actualización pendiente

        if (lazy[p] == 2) {  // Operación de flip (cambiar 0 ↔ 1)
            st[p] = (R - L + 1) - st[p]; // Invierte todos los bits en el rango
            if (L != R) {  // Si no es hoja, propagar a los hijos
                if (lazy[l(p)] == -1) lazy[l(p)] = 2;
                else if (lazy[l(p)] == 2) lazy[l(p)] = -1; // Cancelar si ya estaba marcado
                else lazy[l(p)] = 1 - lazy[l(p)]; // Invertir 0 ↔ 1

                if (lazy[r(p)] == -1) lazy[r(p)] = 2;
                else if (lazy[r(p)] == 2) lazy[r(p)] = -1;
                else lazy[r(p)] = 1 - lazy[r(p)];
            }
        } else { // lazy[p] es 0 o 1 → Asignar directamente
            st[p] = (R - L + 1) * lazy[p]; // Llenar con 0s o 1s
            if (L != R) { // Propagar a los hijos
                lazy[l(p)] = lazy[p];
                lazy[r(p)] = lazy[p];
            }
        }
        lazy[p] = -1; // Limpiar la actualización
    }

    void update_range(int p, int L, int R, int i, int j, int val) {
        propagate(p, L, R); 
        if (i > j) return;

        if (L >= i && R <= j) { 
            lazy[p] = val;
            propagate(p, L, R);
        } else {
            int m = (L + R) / 2;
            update_range(l(p), L, m, i, min(m, j), val);
            update_range(r(p), m+1, R, max(i, m+1), j, val);
            st[p] = st[l(p)] + st[r(p)];
        }
    }

    int query_range(int p, int L, int R, int i, int j) {
        propagate(p, L, R);
        if (i > j) return 0;

        if (L >= i && R <= j) return st[p];

        int m = (L + R) / 2;
        int left_sum = query_range(l(p), L, m, i, min(m, j));
        int right_sum = query_range(r(p), m+1, R, max(i, m+1), j);
        return left_sum + right_sum;
    }

public:
    SegmentTree(int sz) : n(sz), A(n), st(4*n), lazy(4*n, -1) {}

    SegmentTree(const vi &initialA) : SegmentTree((int)initialA.size()) {
        A = initialA;
        build(1, 0, n-1);
    }

    void update_range(int i, int j, int val) { update_range(1, 0, n-1, i, j, val); }

    void flip_range(int i, int j) {
        update_range(1, 0, n-1, i, j, 2); // Usamos 2 para marcar flip
    }

    int count_ones(int i, int j) { return query_range(1, 0, n-1, i, j); }
};

int casos = 1;

void solve(){
    int subCasos = 1;
    int m; cin>>m;
    vector<int> A;
    // cout << "m: " << m << endl; 
    for(int e = 0 ; e < m; e++){
        int total; cin>>total;
        string str,res; cin>>str;
        res.reserve(str.size()*total);
        // cout << "str: " << str << endl;
        for(int e = 0 ;e < total ;e++)
            res += str;
        // cout << "res: " << res << endl;
        for(int e = 0 ; e < res.size();e++){
            if(res[e] == '1') A.pb(1);
            else A.pb(0);
        }
    }
    SegmentTree ST(A);
    int q;cin>>q;
    cout << "Case " << casos++ << ":" << endl;
    for(int e = 0 ; e < q; e++){
        char ch;cin>>ch;
        int a,b;cin>>a>>b;
        if(ch == 'F'){
            ST.update_range(a,b,1);
        }else if(ch == 'E'){
            ST.update_range(a,b,0);
        }else if (ch == 'I'){
            ST.flip_range(a,b);
        }else{
            cout << "Q" << subCasos++ << ": " <<ST.count_ones(a,b) << endl;
        }
    }
}
void solve2(){
    std::string str = "Hola";
    int n = 3;
    
    std::string resultado;
    resultado.reserve(str.size() * n); // Optimiza la asignación de memoria
    
    for (int i = 0; i < n; i++) {
        resultado += str;
    }
    
    std::cout << resultado << std::endl; // "HolaHolaHola"
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

    // vi A = {0, 1, 0, 1, 1, 0, 0, 1}; 
    // SegmentTree st(A);

    // cout << "Número de unos en [0, 7]: " << st.count_ones(0, 7) << endl; // 4
    // cout << "Número de unos en [2, 5]: " << st.count_ones(2, 5) << endl; // 2

    // st.flip_range(2, 6); // Invertimos el rango [2,6]
    // cout << "Después de invertir, número de unos en [0, 7]: " << st.count_ones(0, 7) << endl; // 5
    // cout << "Número de unos en [2, 5]: " << st.count_ones(2, 5) << endl; // 2

    // st.update_range(0,3,0);
    // cout << "Número de unos en [0, 7]: " << st.count_ones(0, 7) << endl; // 4


    // st.flip_range(2, 6);   0 1 1 0 0 1 1 1
    // st.update_range(0,3,0); 0 0 0 0 0 1 1 1 ok
    // st.update_range(0,3,1); 1 1 1 1 0 1 1 1 x

    return 0;
}