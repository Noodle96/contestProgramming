/*
==========================================================
|  Archivo       : Flakes.cpp
|  Autor         : Russell
|  Fecha         : 2025-10-11 15:49
|--------------------------------------------------------
|  Tópicos utilizados:
|  - rpc
|  - implementation
|  - flood fill
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
    int n, m; cin >> n >> m;
    vector<vector<char>> grid(n,vector<char>(m,'.'));
    vector<pii> starts;
    for(int i = 0 ;i < n ; i++){
        for(int j = 0 ;j < m ; j++){
            char c; cin >> c;
            grid[i][j] = c;
            if(c == '+') starts.pb({i,j});
        }
    }

    auto dfs = [&](int x, int y) -> int {
        int minimoAlcance = INT_MAX;
        // contemos hasta donde podemos llegar para la derecha(-) como maximo
        int current_x = x;
        int current_y = y + 1;
        while(current_y < m){
            if(grid[current_x][current_y] == '-') current_y++;
            else break;
        }
        minimoAlcance = min(minimoAlcance, current_y - (y + 1));

        // contemos hasta donde podemos llegar para la izquierda(-) como maximo
        current_x = x;
        current_y = y - 1;
        while(current_y >= 0){
            if(grid[current_x][current_y] == '-') current_y--;
            else break;
        }
        minimoAlcance = min(minimoAlcance, (y - 1) - current_y);
        // contemos hasta donde podemos llegar para abajo(|) como maximo
        current_x = x + 1;
        current_y = y;
        while(current_x < n){
            if(grid[current_x][current_y] == '|') current_x++;
            else break;
        }
        minimoAlcance = min(minimoAlcance, current_x - (x + 1));
        // contemos hasta donde podemos llegar para arriba(|) como maximo
        current_x = x - 1;
        current_y = y;
        while(current_x >= 0){
            if(grid[current_x][current_y] == '|') current_x--;
            else break;
        }
        minimoAlcance = min(minimoAlcance, (x - 1) - current_x);
        // contemos hasta donde podemos llegar para la diagonal derecha-abajo(\) como maximo
        current_x = x + 1;
        current_y = y + 1;
        while(current_x < n && current_y < m){
            if(grid[current_x][current_y] == '\\') current_x++, current_y++;
            else break;
        }
        minimoAlcance = min(minimoAlcance, current_x - (x + 1));
        // contemos hasta donde podemos llegar para la diagonal izquierda-arriba(\) como maximo
        current_x = x - 1;
        current_y = y - 1;
        while(current_x >= 0 && current_y >= 0){
            if(grid[current_x][current_y] == '\\') current_x--, current_y--;
            else break;
        }
        minimoAlcance = min(minimoAlcance, (x - 1) - current_x);

        // contemos hasta donde podemos llegar para la diagonal derecha-arriba(/) como maximo
        current_x = x - 1;
        current_y = y + 1;
        while(current_x >= 0 && current_y < m){
            if(grid[current_x][current_y] == '/') current_x--, current_y++;
            else break;
        }
        minimoAlcance = min(minimoAlcance, (x - 1) - current_x);
        // contemos hasta donde podemos llegar para la diagonal izquierda-abajo(/)
        current_x = x + 1;
        current_y = y - 1;
        while(current_x < n && current_y >= 0){
            if(grid[current_x][current_y] == '/') current_x++, current_y--;
            else break;
        }
        minimoAlcance = min(minimoAlcance, current_x - (x + 1));
        return minimoAlcance;
    };

    int ansMaximo = -1;
    for(auto si: starts){
        int x = si.first;
        int y = si.second;
        auto minimoAlcance = dfs(x,y);
        ansMaximo = max(ansMaximo, minimoAlcance);
    }
    cout << ansMaximo << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;
    //cin >> t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}

