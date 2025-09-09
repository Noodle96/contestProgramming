/*
==========================================================
|  Archivo       : Fair.cpp
|  Autor         : Russell
|  Fecha         : 2025-09-06
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

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

int mygcd(int a, int b){
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b){ int t = a % b; a = b; b = t; }
    return a;
}

int gcd_runs(const vector<string>& g){
    int h = (int)g.size(), w = (int)g[0].size();
    int acc = 0;

    for(int i = 0; i < h; ++i){
        int j = 0;
        while(j < w){
            if(g[i][j] == '#'){
                int len = 0;
                while(j < w && g[i][j] == '#'){ ++len; ++j; }
                acc = mygcd(acc, len);
            }else ++j;
        }
    }
    for(int j = 0; j < w; ++j){
        int i = 0;
        while(i < h){
            if(g[i][j] == '#'){
                int len = 0;
                while(i < h && g[i][j] == '#'){ ++len; ++i; }
                acc = mygcd(acc, len);
            }else ++i;
        }
    }
    return acc;
}

vector<vector<int>> build_pref(const vector<string>& g){
    int h = (int)g.size(), w = (int)g[0].size();
    vector<vector<int>> pref(h+1, vector<int>(w+1, 0));
    for(int i = 0; i < h; ++i){
        for(int j = 0; j < w; ++j){
            pref[i+1][j+1] = pref[i+1][j] + pref[i][j+1] - pref[i][j] + (g[i][j] == '#');
        }
    }
    return pref;
}
int rect_sum(const vector<vector<int>>& P, int r1, int c1, int r2, int c2){
    return P[r2][c2] - P[r1][c2] - P[r2][c1] + P[r1][c1];
}

bool can_tile_k(const vector<string>& g, int k, const vector<vector<int>>& pref){
    int h = (int)g.size(), w = (int)g[0].size();
    vector<vector<int>> D(h+1, vector<int>(w+1, 0));
    vector<int> colAcc(w+1, 0);

    for(int i = 0; i < h; ++i){
        int rowAcc = 0;
        for(int j = 0; j < w; ++j){
            colAcc[j] += D[i][j];
            rowAcc += colAcc[j];
            int cover = rowAcc;

            if(g[i][j] == '#'){
                if(cover == 0){
                    if(i + k > h || j + k > w) return false;
                    int ones = rect_sum(pref, i, j, i + k, j + k);
                    if(ones != k * k) return false;

                    D[i][j] += 1;
                    D[i + k][j] -= 1;
                    D[i][j + k] -= 1;
                    D[i + k][j + k] += 1;

                    colAcc[j] += 1;
                    rowAcc += 1;
                }
            }else{
                if(cover > 0) return false;
            }
        }
    }
    return true;
}

void solve(){
    int h,w; cin >> h >> w;
    vector<string> g(h);
    for(int i = 0; i < h; ++i) cin >> g[i];

    int base = gcd_runs(g);
    vector<int> divs;
    for(int d = 1; d * 1LL * d <= base; ++d){
        if(base % d == 0){
            divs.push_back(d);
            if(d * 1LL * d != base) divs.push_back(base / d);
        }
    }
    sort(divs.begin(), divs.end(), greater<int>());

    auto pref = build_pref(g);

    for(int k : divs){
        if(can_tile_k(g, k, pref)){
            cout << k << endl;
            return;
        }
    }
    cout << 1 << endl;
}
void solve2(){
    int x,y; cin >> x >> y;
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