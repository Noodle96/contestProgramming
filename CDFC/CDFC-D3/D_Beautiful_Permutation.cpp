/*
==========================================================
|  Archivo       : D_Beautiful_Permutation.cpp
|  Autor         : Russell
|  Fecha         : 2025-10-17 19:24
|--------------------------------------------------------
|  Tópicos utilizados:
|  - div3
|  - interaction
|  - binary search
==========================================================
*/

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;

using ll = long long;
using i64 = int64_t;
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

ll gcd(ll a,ll b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
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
int bitlen_unsigned(unsigned long long n){
    // __builtin_clzll: Cuenta los ceros a la izquierda
    return (n == 0) ? 1 : 64 - __builtin_clzll(n);
}

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

i64 ask_sum_p(int l, int r){
    cout << "1 " << l << " " << r << endl;
    i64 x; cin >> x;
    return x;
}
i64 ask_sum_a(int l, int r){
    cout << "2 " << l << " " << r << endl;
    i64 x; cin >> x;
    return x;
}

void solve(){
    int n; cin >> n;
    i64 sumP = ask_sum_p(1, n);
    i64 sumA = ask_sum_a(1, n);
    i64 diff = sumA - sumP;

    int lo = 1, hi = n;
    while(lo < hi){
        int mid = (lo+hi) >> 1;
        i64 xp = ask_sum_p(1, mid);
        i64 xa = ask_sum_a(1, mid);
        i64 delta = xa - xp;
        if(delta > 0){
            hi = mid; // Aún hay diferencia en la mitad izquierda
        }else{
            lo = mid + 1; //  todavia estamos antes de L
        }
    }
    int L = lo;
    int R = L + (int)diff - 1;
    cout << "! " << L << " " << R << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // #ifdef DEBUG
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif
    int t;
    cin >> t;
    // t = 1;
    while(t--){
        solve();
    }
    return 0;
}