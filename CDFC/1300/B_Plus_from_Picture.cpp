/*
==========================================================
|  Archivo       : B_Plus_from_Picture.cpp
|  Autor         : Russell
|  Fecha         : 2025-09-17 16:38
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Dfs and similars
|  - *training
|  - *1300
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
int h,w;
vector<vector<char>> grid;
vector<vector<bool>> isVisited;
int numComponents;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool isValidPosition(int x, int y){
    return (x >= 0 && x < h && y >= 0 && y < w);
}

bool cruz(int x, int y){
    bool res = true;
    res &= isValidPosition(x-1,y) && grid[x-1][y] == '*';
    res &= isValidPosition(x+1,y) && grid[x+1][y] == '*';
    res &= isValidPosition(x,y-1) && grid[x][y-1] == '*';
    res &= isValidPosition(x,y+1) && grid[x][y+1] == '*';
    return res;
}

void dfs(int x, int y){
    if(isVisited[x][y]) return;
    isVisited[x][y] = true;
    for(int dir = 0 ; dir < 4 ; dir++){
        int newX = x + dx[dir];
        int newY = y + dy[dir];
        if(isValidPosition(newX,newY) && grid[newX][newY] == '*'){
            dfs(newX,newY);
        }
    }
}

void solve(){
    cin >> h >> w;
    grid.assign(h, vector<char>(w));
    isVisited.assign(h, vector<bool>(w,false));
    for(int i = 0;i < h ; i++){
        string s; cin >> s;
        for(int j = 0 ; j < w ; j++){
            grid[i][j] = s[j];
        }
    }
    numComponents = 0;
    for(int i = 0 ; i < h ;i++){
        for(int j = 0 ; j < w ; j++){
            if(grid[i][j] == '*' && !isVisited[i][j]){
                dfs(i,j);
                numComponents++;
            }
        }
    }
    if(numComponents == 1){
        int numCruzes = 0;
        for(int i = 0 ; i < h; i++){
            for(int j = 0 ;j < w ; j++){
                if(grid[i][j] == '*'){
                    if(cruz(i,j)){
                        numCruzes++;
                    }
                }
            }
        }

        int lenV = 0, lenH = 0;
        int contV = 0, contH = 0;
        for(int i = 0 ; i < h; i++){
            lenV = 0;
            for(int j = 0 ; j < w; j++){
                if(grid[i][j] == '*'){
                    lenV++;
                }
            }
            if(lenV >= 2) contV++;
        }
        for(int i = 0;i < w; i++){
            lenH = 0;
            for(int j = 0; j < h; j++){
                if(grid[j][i] == '*'){
                    lenH++;
                }
            }
            if(lenH >= 2) contH++;
        }
        if(numCruzes == 1 && contH == 1 && contV == 1){
            cout << "YES" << endl;
        } else cout << "NO" << endl;
    }else{
        cout << "NO" << endl;
    }
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