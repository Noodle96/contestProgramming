/*
==========================================================
|  Archivo       : C_Sagheer_and_Nubian_Market.cpp
|  Autor         : Russell
|  Fecha         : 2026-04-07 18:34
|--------------------------------------------------------
|  Tópicos utilizados:
|  - binary search
|  - sorting
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
    int n; cin >> n;
    ll S; cin >> S;
    vector<pair<int,int>> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    auto can = [&](ll k) -> bool {
        vector<ll> costs(n);
        for(int i = 0; i < n; i++){
            costs[i] = (a[i].first + (a[i].second)*k);
        }
        ll total = 0;
        sort(all(costs));
        for(int i = 0; i < k; i++){
            total += costs[i];
        }
        if(total > S) return false;
        return true;
    };

    ll l = 1, r = (ll)n;
    ll ans = -1;
    while(l <= r){
        ll mid = l + (r -l ) / 2;
        // queremos el maximo valido, entonces si mid es valido vamos a la derecha 
        if(can(mid)){
            ans = mid;
            l = mid + 1;
        }else{
            r = mid  - 1;
        }
    }
    if(ans == -1){
        cout << "0 0\n";
        return;
    }
    ll k = ans;
    vector<ll> costs(n);
    for(int i = 0; i < n; i++){
        costs[i] = (a[i].first + (a[i].second)*k);
    }
    sort(all(costs));
    ll minTotal = 0;
    for(int i = 0; i < k; i++){
        minTotal += costs[i];
    }
    cout << k << " " << minTotal << endl;
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