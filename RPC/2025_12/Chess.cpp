/*
==========================================================
|  Archivo       : Chess.cpp
|  Autor         : Russell
|  Fecha         : 2025-10-11 16:38
|--------------------------------------------------------
|  Tópicos utilizados:
|  - rpc
|  - implementation
|  - dfs
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
struct P{
    char t;
    int r,c;
};
// Movimiento del caballo
const int dr[8] = {+2,+2,+1,+1,-1,-1,-2,-2};
const int dc[8] = {+1,-1,+2,-2,+2,-2,+1,-1};
// Movimiento de la torre
const int drR[4] = {-1,+1,0,0};
const int dcR[4] = {0,0,-1,+1};

// Movimiento de la reina
const int drQ[8] = {-1,-1,-1,0,0,+1,+1,+1};
const int dcQ[8] = {-1,0,+1,-1,+1,-1,0,+1};

void solve(){
    int N, M; cin >> N >> M;
    vector<vector<char>> atk(N, vector<char>(N, 0));
    vector<P> pieces;
    for (int i = 0; i < M; ++i) {
        char T; int r, c;
        cin >> T >> r >> c;
        r--; c--;
        pieces.pb({T, r, c});
    }

    auto mark_cell = [&](int r, int c) {
        if (0 <= r && r < N && 0 <= c && c < N) atk[r][c] = 1;
    };

    // Marcamos rayos completos en una dirección (dr,dc)
    auto mark_ray = [&](int r, int c, int dr, int dc) {
        int rr = r + dr, cc = c + dc;
        while (0 <= rr && rr < N && 0 <= cc && cc < N) {
            atk[rr][cc] = 1;
            rr += dr; cc += dc;
        }
    };

    for (const auto &p : pieces) {
        int r = p.r;
        int c = p.c;
        mark_cell(r, c);

        if (p.t == 'N') {
            // Movimientos de caballo (8 posibles)
            for (int k = 0; k < 8; ++k)
                mark_cell(r + dr[k], c + dc[k]);
        } else if (p.t == 'R') {
            // Fila y columna completas (4 rayos)
            // Movimiento de la torre
            for(int k = 0; k < 4; k++){
                mark_ray(r,c, drR[k], dcR[k]);
            }
        } else if (p.t == 'Q') {
            // Torre (4) + diagonales (4) = 8 rayos
            // Movimiento de la reina
            for(int k = 0; k < 8; k++){
                mark_ray(r,c, drQ[k], dcQ[k]);
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            ans += atk[i][j];

    cout << ans << endl;
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