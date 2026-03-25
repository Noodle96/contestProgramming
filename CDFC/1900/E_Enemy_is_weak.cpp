/*
==========================================================
|  Archivo       : E_Enemy_is_weak.cpp
|  Autor         : Russell
|  Fecha         : 2026-03-24 11:27
|--------------------------------------------------------
|  Tópicos utilizados:
|  - data structures: fenwick tree
|  - path compression
|  - combinatorics
|  - *1900
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

class Fenwick{
    private:
        int n;
        vector<ll> bit;
    public:
        Fenwick(int n): n(n), bit(n+1,0) {}
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
            return query(r) - query(l - 1);
        }
};

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n ; i++){
        cin >> a[i];
    }

    // inversion count de tripletes
    // comprimimos ya que ai <= 1e9
    vector<ll> vals = a;
    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());

    auto get_id = [&](ll x) -> int {
        return lower_bound(all(vals), x) - vals.begin() + 1;
    };

    // L[j] = cantidad de i<j con a[i] > a[j]
    //      L[J] = j - leq(j)
    // L[j] la cantidad de elementos que estan a la izquierda mayores que a[j].

    // R[j] = cantidad de k > j con a[k] < a[j]
    // R[j] = cantidad de j < k con a[j] > a[k] CLASICO inversion counts
    // R[j] = cantidad de elementos que estan a la derecha de a[j] que son menores.

    // ans = L[j] * R[j]
    vector<ll> L(n,0), R(n,0);
    // IZQUIERDA
    Fenwick ft_left(vals.size());
    for(int i = 0; i < n; i++){
        int id = get_id(a[i]);
        L[i] = (ll)i - ft_left.query(id); // <=
        ft_left.update(id, +1); 
    }
    Fenwick ft_right(vals.size());
    // clasico inversion count
    for(int i = n - 1; i >= 0; i--){
        int id =  get_id(a[i]);
        R[i] = ft_right.query(id - 1); // <
        ft_right.update(id, +1);
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans  += (L[i]* R[i]);
    }
    cout << ans << "\n";

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
        solve();
    }
    return 0;
}