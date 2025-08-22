/*
==========================================================
|  Archivo       : D_From_1_to_Infinity.cpp
|  Autor         : Russell
|  Fecha         : 2025-08-21 11:36
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Math
==========================================================
*/

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
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
using vll = vector<ll>;

#define pb push_back
#define mp make_pair

const ll INF = 1e18;

ll gcd(ll a,ll b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

// Suma de dígitos de 1..n en O(log n)
ll digit_sum_upto(ll n) {
    if (n <= 0) return 0;
    ll res = 0;
    ll p = 1; // posición (unidades, decenas, centenas...)
    while (p <= n) {
        ll higher = n / (p * 10);
        ll curr   = (n / p) % 10;
        ll lower  = n % p;

        // Suma de ciclos completos
        res += higher * 45 * p;

        // Suma de los dígitos de la posición actual
        res += (curr * (curr - 1)) / 2 * p;
        res += curr * (lower + 1);

        p *= 10;
    }
    return res;
}

// Suma de dígitos en el rango [L, R]
ll digit_sum_range(long long L, long long R) {
    if (L > R) return 0;
    return digit_sum_upto(R) - digit_sum_upto(L - 1);
}

void solve(){
   ll k;
    cin >> k;

    ll sum = 0;
    ll remaining = k;
    int d = 1;

    while (true) {
        // cout << "para k: " <<k << endl;
        ll count_numbers = 9LL * (long long)pow(10, d - 1);
        ll block_size = count_numbers * d;

        if (remaining > block_size) {
            // suma completa del bloque de d dígitos
            ll first = (d == 1 ? 1 : (long long)pow(10, d - 1));
            ll last  = (long long)pow(10, d) - 1;
            sum += digit_sum_range(first, last);
            remaining -= block_size;
            d++;
        } else {
            // suma parcial dentro del bloque
            ll first = (d == 1 ? 1 : (long long)pow(10, d - 1));
            ll q = remaining / d; // números completos
            ll r = remaining % d; // dígitos extra

            if (q > 0) {
                sum += digit_sum_range(first, first + q - 1);
            }

            if (r > 0) {
                ll next = first + q;
                string s = to_string(next);
                for (int i = 0; i < r; i++) sum += s[i] - '0';
            }
            break;
        }
    }
    cout << sum << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t; cin >> t;
    while(t--) solve();
    return 0;
}