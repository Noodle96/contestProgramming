/*
==========================================================
|  Archivo       : F_Quests.cpp
|  Autor         : Russell
|  Fecha         : 2026-04-08 17:03
|--------------------------------------------------------
|  Tópicos utilizados:
|  - binary search
|  - sorting
|  - greedy
|  - *1500
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

void solve() {
    int n, d;
    ll C;
    cin >> n >> C >> d;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    // ordenamos descendentemente
    sort(all(a), [&](ll x, ll y){
        return x > y;
    });
    
    auto can = [&](ll k) -> bool {
        // queremos el maximo true
        // previo ordenado
        // solo recorremos los k + 1 elementos mas grandes
        // ya que volveremos a utilizarlos en el siguiente ciclo
        ll total = 0;
        for(int i = 0; i < k +1 && i < n; i++){
            int vecesElementoIsimo = ceildiv(d - i, k+1);
            // cout << "\t\t\ta[i]: " << a[i] << " vecesElementoIsimo: " << vecesElementoIsimo << "\n";
            total += (a[i]* vecesElementoIsimo);
            // cout<< "\t\t total: " << total << "\n";
            if(total >= C) return true;
        }
        return false;
    };

    ll l = 0, r = 1e12;
    ll ans = -1;
    while(l <= r){
        ll mid = l + (r - l) / 2;
        // cout << "mid: " << mid << "\n";
        // buscamos el mayor true valido
        if(can(mid)){
            // cout << "\tderecha\n";
            ans = mid;
            l = mid + 1;
        }else{
            // cout << "\tizquierda\n";
            r = mid - 1;
        }

    }
    if(ans == -1){
        cout << "Impossible\n";
        return;
    }
    if(ans == 1e12){
        cout << "Infinity\n";
        return;
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
    cin >> t;
    // t = 1;
    while (t--) {
        solve();
    }
    return 0;
}