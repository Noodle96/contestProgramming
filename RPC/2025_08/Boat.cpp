/*
==========================================================
|  Archivo       : Boat.cpp
|  Autor         : Russell
|  Fecha         : 2025-07-26 14:32
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Implementation
|  - Data Structures
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

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    // last_start[c]: muelle donde la tarjeta c empezó el viaje, o -1 si no está en viaje
    vector<int> last_start(m+1, -1);
    // charge[c]: coste acumulado para la tarjeta c
    vector<long long> charge(m+1, 0);

    for (int i = 0; i < k; i++) {
        int p, c;
        cin >> p >> c;

        if (last_start[c] == -1) {
            // Tap in
            last_start[c] = p;
        } else {
            // Tap out
            int start = last_start[c];
            long long cost;
            if (p == start) {
                // mismo muelle ⇒ penalización
                cost = 100;
            } else {
                // coste normal = |i - j|
                cost = abs(p - start);
            }
            charge[c] += cost;
            last_start[c] = -1;
        }
    }

    // Penalizar todas las tarjetas que quedaron (en viaje) sin hacer tap out
    for (int c = 1; c <= m; c++) {
        if (last_start[c] != -1) {
            charge[c] += 100;
        }
    }

    for (int c = 1; c <= m; c++) {
        cout << charge[c] << (c < m ? ' ' : '\n');
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