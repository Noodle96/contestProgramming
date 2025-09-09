/*
==========================================================
|  Archivo       : Dryland.cpp
|  Autor         : Russell
|  Fecha         : 2025-09-06
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Brute force
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

const int INF = 1e9;

ll gcd(ll a,ll b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

int r, c; 
vector<string> grid;

int particularCase(int e, int j){
    if(grid[e][j] == '0') return 0;
    int best = 0;
    int minimoCol = INF;
    for(int p = e; p < r; p++){
        if(grid[p][j] != '1') break;
        int ancho = 0;
        for(int q = j; q < c && grid[p][q] == '1'; q++) ancho++;

        minimoCol = min(minimoCol, ancho);
        int altura = p - e + 1;
        best = max(best, minimoCol * altura);
    }
    return best;
}

void solve(){
    cin >> r >> c;
    grid.resize(r);
    for(int i = 0; i < r; i++) cin >> grid[i];
    int ans_maximo = -INF;
    for(int e = 0 ; e < r; e++){
        for(int j = 0 ; j < c; j++){
            int ans = particularCase(e, j);
            ans_maximo = max(ans_maximo, ans);
        }
    }
    cout << ans_maximo << endl;
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