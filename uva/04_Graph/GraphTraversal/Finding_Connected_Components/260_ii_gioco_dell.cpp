#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define msg(str,str2) cout << str << str2<< endl
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

#define pb push_back
#define mp make_pair

int gcd(int a,int b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
int n;
const int N = 2e2+5;
char grid[N][N];
bool isVisited[N][N];
const int dx[] = {-1, -1, 0, 0, 1, 1};
const int dy[] = {0, -1,-1, 1, 1, 0};
int contadorComponentes;
set<int> index_colums;
int caso = 1;

bool isValidPosition(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < n;
}

void dfs(int x, int y){
    if(isVisited[x][y]) return;
    isVisited[x][y] = true;
    index_colums.insert(y);
    for(int e = 0 ; e < 6; e++){
        int new_x = x + dx[e];
        int new_y = y + dy[e];
        if(isValidPosition(new_x,new_y) && grid[new_x][new_y] == 'w'){
            dfs(new_x,new_y);
        }
    }
}

void solve(){
    while(cin>>n){
        if(n!= 0){
            for(int i = 0 ; i < n; i++){
                for(int j = 0 ; j < n; j++){
                    cin>>grid[i][j];
                    isVisited[i][j] = false; 
                }
            }
            // cout << "grid: " << endl;
            // for(int i = 0 ; i < n; i++){
            //     for(int j = 0 ; j < n; j++){
            //         cout << grid[i][j] << " ";
            //     }cout << endl;
            // }cout << endl;
            // DFS para el white
            // contadorComponentes = 0;
            index_colums.clear();
            bool ans = false;
            for(int e = 0 ;e < n ; e++){
                for(int j = 0 ; j < n; j++){
                    if(isVisited[e][j] == false && grid[e][j] == 'w'){
                        dfs(e,j);
                        // contadorComponentes++;
                        // validar si es que index_column tiene todas las columnas
                        if(index_colums.size() == n){
                            // cout << "yes " << contadorComponentes << endl;
                            ans = true;
                        }
                        index_colums.clear();
                    }
                }
            }
            // cout << "No " << contadorComponentes << endl;
            if(ans) cout << caso++ << " W" << endl;
            else cout << caso++ << " B" << endl;
        }
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