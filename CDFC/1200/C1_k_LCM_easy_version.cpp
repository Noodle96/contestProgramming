/*
==========================================================
|  Archivo       : C1_k_LCM_easy_version.cpp
|  Autor         : Russell
|  Fecha         : 2026-11-06 17:36
|--------------------------------------------------------
|  Tópicos utilizados:
|  - math
|  - lcm
|  - *1200
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
    ll n;
    int k;
    cin >> n >> k;
    if(n % 3 == 0){
        cout << n / 3 << " " <<  n / 3 << " " << n / 3 << "\n";
    }else{
        // Caso n % 3 == 2 y n % 3 == 1 
        if(n & 1){
            // impar
            cout << 1 << " ";
            n --;
            cout << n /2 << " " << n / 2 << "\n";
        }else{
            // par
            ll temp = n - 2;
            if((temp / 2) & 1){
                cout << n / 2 << " " << n / 4 << " " << n / 4 << "\n";
            }else{
                cout << 2 << " " << temp / 2 << " " << temp / 2 << "\n";
            }
        }

    }
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