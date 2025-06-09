/*
==========================================================
|  Archivo       : Fumblemore.cpp
|  Autor         : Russell
|  Fecha         : 2025-06-07 16:23
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Tema 1
|  - Tema 2
|  - Tema 3
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
using u128 = unsigned __int128;
const u128 LIMIT = (u128)1 << 47;

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


void solve(){
    string s;
    if (!getline(cin, s)) return;

    // 1) Validación básica
    int m = s.size();
    if (m == 0 || s.back() != 'O') {
        cout << "INVALID\n";
        return;
    }
    for (int i = 0; i < m; ++i) {
        if (s[i] != 'E' && s[i] != 'O') {
            cout << "INVALID\n";
            return;
        }
        if (i+1 < m && s[i] == 'O' && s[i+1] == 'O') {
            cout << "INVALID\n";
            return;
        }
    }

    // 2) Buscamos el mínimo n0
    u128 best = 0;      // 0 = sin candidato aún
    for (int p = 1; p <= 47; ++p) {
        u128 x = (u128)1 << p;  // n_m = 2^p
        bool ok = true;
        // invertimos los m pasos
        for (int i = m - 1; i >= 0; --i) {
            if (s[i] == 'E') {
                // n_i debe ser n_{i+1}*2 y no potencia de 2
                x = x * 2;
                if (x > LIMIT || ((x & (x - 1)) == 0)) {
                    ok = false;
                    break;
                }
            } else {
                // 'O': n_i = (n_{i+1}-1)/3, divisible, impar >1
                if ((x - 1) % 3 != 0) {
                    ok = false;
                    break;
                }
                x = (x - 1) / 3;
                if (x <= 1 || (x % 2 == 0)) {
                    ok = false;
                    break;
                }
            }
        }
        if (!ok) continue;
        // x es candidato n0
        if (best == 0 || x < best) {
            best = x;
        }
    }

    if (best == 0) {
        // no se encontró (aunque en teoría, para entradas válidas siempre hay solución)
        cout << "INVALID\n";
    } else {
        // imprimir u128
        uint64_t ans = (uint64_t)best;
        cout << ans << "\n";
    }

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