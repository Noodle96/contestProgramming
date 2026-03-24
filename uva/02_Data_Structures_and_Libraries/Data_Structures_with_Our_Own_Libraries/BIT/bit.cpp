/*
==========================================================
|  Archivo       : bit.cpp
|  Autor         : Russell
|  Fecha         : 2026-03-20 17:21
|--------------------------------------------------------
|  Tópicos utilizados:
|  - femwick tree
|  - training
==========================================================
*/

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;
using i64 = int64_t;
using i32 = int32_t;
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

const int INF = 1e9;

ll gcd(ll a, ll b) {
    if (a % b == 0) return b;
    else return gcd(b, a % b);
}

ll floordiv(ll a, ll b) {
    if (a >= 0) return a / b;
    return - ( (-a + b - 1) / b );
}

ll ceildiv(ll a, ll b) {
    // ceil(a/b) = -floor((-a)/b)
    if (a >= 0) return (a + b - 1) / b;
    return - ( (-a) / b );
}

int bitlen_unsigned(unsigned long long n) {
    // __builtin_clzll: Cuenta los ceros a la izquierda
    return (n == 0) ? 1 : 64 - __builtin_clzll(n);
}

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}


void intervals(){
    int n = 100;
    // [ i − (i & − i) + 1, i ]
    for(int i = 1; i <= n; i++){
        int l = i - (i&-i) + 1;
        int r = i;
        cout << "[" << l << "," << r << "]\n";
    }
}


class Fenwick{
    private:
        int n;
        vector<ll> bit;
    public:
        Fenwick(int n): n(n), bit(n+1, 0){}
        void update(int idx, ll val){
            while(idx <= n){
                bit[idx] += val;
                idx += (idx & -idx);
            }
        }
        ll query(int idx){
            ll sum = 0;
            while(idx > 0){
                sum += bit[idx];
                idx -= (idx & -idx);
            }
            return sum;
        }
        ll query(int l, int r){
            return query(r) - query(l-1);
        }
};

/*
    (PREFI SUM DINAMICO)
    Tenemos un arreglo de n elementos, debemos procesar operaciones
    1 i x:  sumar x a a[i]
    2 l r: imprimit suma de [l,r]
    Input:
    5 5
    1 1 2
    1 3 5
    2 1 3
    1 5 1
    2 1 5
*/

void problem1(){
    int n,m;
    cin >> n >> m;
    Fenwick ft(n);
    for(int j = 0; j < m; j++){
        int type; cin >> type;
        if(type == 1){
            int i;
            ll x;
            cin >> i >> x;
            ft.update(i, x);
        }else{
            // type = 2
            int l, r;
            cin >> l >> r;
            ll ans = ft.query(l,r);
            cout << ans << "\n";
        }
    }
}

/*
    2. Inversion Count
    Idea:
        contar pares i < j y a[i] > a [j]
    Problema:
        Dado un arreglo, contar cuántas inversiones tiene.
    Input:
        5
        3 1 2 5 4
    Output:
        3

*/
void problem2(){
    int n;
    cin >> n;
    vector<ll> vec(n);
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }

    // Implementacion con compresion
    auto inversion_count = [&]() -> int {
        vector<ll> vals = vec;
        sort(all(vals));
        vals.erase(unique(all(vals)), vals.end());
        auto get_id = [&](ll x) -> int {
            return lower_bound(all(vals), x) - vals.begin() + 1;
        };

        Fenwick ft(vals.size());
        ll ans = 0;
        for(int i = n -1; i >= 0; i--){
            int id = get_id(vec[i]);
            ans += ft.query(id); // <=
            ft.update(id, +1);
        }
        return ans;
    };

    auto ans = inversion_count();
    cout << ans << "\n";
}

/*
🧠 4. Frequency queries
📌 Idea Contar ocurrencias en rango
🧩 Problema Dado un arreglo,
responder: ¿cuántos valores ≤ x en prefijo?
Entrada
5
4 2 5 2 3 
3
2
5
3
Salida
2
5
3
*/
void problem3(){
    int n;
    cin >> n;

    vector<int> a(n);
    int mx = 0;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    Fenwick ft(mx);

    // Insertar frecuencias
    for(int i = 0; i < n; i++) {
        ft.update(a[i], 1);
    }

    int q;
    cin >> q;

    while(q--) {
        int x;
        cin >> x;

        if(x > mx) x = mx; // por seguridad
        cout << ft.query(x) << "\n";
    }
}

/*
    🧠 5. Order statistics (k-th smallest)
    📌 Idea Encontrar el k-ésimo elemento
    🧩 Problema Dado un multiset dinámico,
    soportar: insertar número eliminar número encontrar k-ésimo menor
    📥 Entrada
    q = 8
    insert 3
    insert 1
    insert 5
    insert 1
    insert 6
    insert 7
    insert 7
    kth 5
    📤 Salida
    6
    Representacio bit
    0 1 2 3 4 5 6 7 8 9
fre 0 2 0 1 0 1 1 2 0 0
bit 0 2 2 3 3 4 5 7 7 7
    💡 BIT hace frecuencia acumulada binary search sobre BIT
*/

int kth(Fenwick &ft, int n, int k) {
    int l = 1, r = n;
    int ans = -1;

    while(l <= r) {
        int mid = (l + r) / 2;

        if(ft.query(mid) >= k) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return ans;
}
void problem_kth() {
    int q;
    cin >> q;

    int MAXV = 100000; // depende del rango
    Fenwick ft(MAXV);

    while(q--) {
        string op;
        cin >> op;

        if(op == "insert") {
            int x;
            cin >> x;
            ft.update(x, 1);
        }
        else if(op == "erase") {
            int x;
            cin >> x;
            ft.update(x, -1);
        }
        else {
            int k;
            cin >> k;

            int ans = kth(ft, MAXV, k);
            cout << ans << "\n";
        }
    }
}

/*
    💥 Range Update + Point Query
    🧠 1. IDEA
    Quieres soportar:
        add l r x → sumar x a TODOS los elementos en [l, r]
        get i → obtener el valor actual de a[i]

    type = 1 => l r x
    type = 2 => i

    📥 Input:
    n= 5 q = 5
    1 1 3 2
    1 2 5 1
    2 3
    2 1
    2 5
    0 1 2 3 4 5
    0 2 2 2 0 0
    0 2 3 3 1 1 
    📤 Output:
    3
    2
    1

*/
void problem_range_update()
{
    int n, q;
    cin >> n >> q;

    Fenwick ft(n);

    while (q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int l, r;
            ll x;
            cin >> l >> r >> x;

            ft.update(l, x);
            if (r + 1 <= n)
                ft.update(r + 1, -x);
        }
        else
        {
            int i;
            cin >> i;

            cout << ft.query(i) << "\n";
        }
    }
}

/*
    💀 Range Update + Range Query (DOBLE BIT)
    🧠 1. PROBLEMA

    Ahora queremos soportar:
        - add l r x → sumar x a todos los elementos en [l,r]
        - sum l r → obtener suma de a[l..r]
    📥 INPUT
    5 4
    1 1 3 2
    1 2 5 1
    2 1 5
    2 2 4

    0 1 2 3 4 5
    0 0 0 0 0 0
    0 2 2 2 0 0
    0 2 3 3 1 1
    0 2 5 8 9 10
    📤 SALIDA
    10
    7
*/

void solve() {
    // intervals();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;
    // cin >> t;
    t = 1;
    while (t--) {
        // solve();
        // problem1();
        // problem2();
        // problem_kth();
        problem_range_update();
    }
    return 0;
}