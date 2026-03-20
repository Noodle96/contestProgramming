/*
==========================================================
|  Archivo       : D1_Submarine_in_the_Rybinsk_Sea_easy_edition.cpp
|  Autor         : Russell
|  Fecha         : 2026-03-11 10:36
|--------------------------------------------------------
|  Tópicos utilizados:
|  - combinatoric
|  - math number
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

const ll MOD = 998244353;

ll modpow(ll a, ll b){
    if(b == 0) return 1;
    ll half = modpow(a, b/2);
    ll res = (half *  half) % MOD;
    if(b & 1){
        res = (res * a) % MOD;
    }
    return res;
}
/*
    n = 3
    12 33 45

    Todas las posibles son:
    1 1 2 2
    1 3 2 3
    1 4 2 5
    3 1 3 2
    3 3 3 3
    3 4 3 5
    4 1 5 2
    4 3 5 3
    4 4 5 5
    _______

    Vemos que :
        primeros * n    esto aporta (primeros * n) * 10^3
        primeros * n    esto aporta (primeros * n) * 10^2
        segundos * n    esto aporta (segundos * n) * 10^1
        segundos * n    esto aporta (segundos * n) * 10^0
        .
        .
        .

*/

void solve() {
    int n; cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    // retornar el tamaño de los numeros a[i](a[i] > 0), todos tienen el mismo tamaño
    auto getLen = [&](ll x) -> int {
        int len = 0;
        while(x){
            len++;
            x /= 10;
        }
        return len;
    };
    ll firstNumber = stoll(a[0]);
    int len = getLen(firstNumber);

    int pow = 2*len - 1;
    ll ans = 0;
    for(int i = 0; i < len; i++){
        ll ans1 = 0;
        for(int j = 0;  j < n; j++){
            int digit = a[j][i] - '0';
            ans1 = (ans1 + digit * n) % MOD;
        }
        ll ans2 = ans1;
        ans1 = (ans1 * modpow(10, pow)) % MOD;

        pow--;
        ans2 = (ans2 * modpow(10, pow)) % MOD;

        ans =  (ans + ans1 + ans2 ) % MOD;
        pow--;
    }

    cout << ans << "\n";

}
void solve2(){
    string a = "45";
    for(int i = 0; i < a.size(); i++){
        int digit = a[i] - '0';
        cout << "digit: " << digit + 13 << "\n";
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
    // cin >> t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}