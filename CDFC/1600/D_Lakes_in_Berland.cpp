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

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

vector<vector<char>> grid;
vector<vector<bool>> isVisited;
vector<vector<int>> idComponent;
int n,m;
int sizeComponent;
int numComponent;

bool isValidPosition(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}


void dfs(int x, int y){
    if(isVisited[x][y]) return;
    isVisited[x][y] = true;
    for(int e = 0 ;e < 4 ; e++){
        int new_x = dx[e] + x;
        int new_y = dy[e] + y;
        if(isValidPosition(new_x, new_y) && grid[new_x][new_y] == '.'){
            dfs(new_x,new_y);
        }
    }
}

void dfs2(int x, int y){
    if(isVisited[x][y]) return;
    isVisited[x][y] = true;
    sizeComponent++;
    idComponent[x][y] = numComponent;
    for(int e = 0 ;e < 4 ; e++){
        int new_x = dx[e] + x;
        int new_y = dy[e] + y;
        if(isValidPosition(new_x, new_y) && grid[new_x][new_y] == '.'){
            dfs2(new_x,new_y);
        }
    }
}

void solve(){
    int k;
    cin>>n>>m>>k;
    grid.assign(n,vector<char>(m));
    isVisited.assign(n,vector<bool>(m,false));
    idComponent.assign(n,vector<int>(m,-1));
    string temp;
    for(int e = 0 ; e < n; e++){
        cin>>temp;
        for(int j = 0 ; j < m; j++){
            grid[e][j] = temp[j];
        }
    }
    // recorremos la orilla superiro e inferior
    // for(int e = 0 ; e < n; e += (n-1)){
    //     for(int j = 0 ; j < m; j++){
    //         if(grid[e][j] == '.') dfs(e,j);
    //     }
    // }
    for(int j = 0; j < m; j++){
        if(grid[0][j] == '.') dfs(0,j);
    }
    for(int j = 0; j < m; j++){
        if(grid[n-1][j] == '.') dfs(n-1,j);
    }  

    // recorremos la orilla izquierda y derecha
    // for(int e = 0  ; e < m; e+=(m-1)){
    //     for(int j = 0 ; j < n ; j++){
    //         if(grid[j][e] == '.') dfs(j,e);
    //     }
    // }
    for(int j = 0 ; j < n ; j++){
        if(grid[j][0] == '.') dfs(j,0);
    }
    for(int j = 0 ; j < n ; j++){
        if(grid[j][m-1] == '.') dfs(j,m-1);
    }

    //ahorra no nos preocupamos de las orillas
    numComponent = 0;
    vector<pair<int,int>> ans;
    for(int e = 0 ; e < n; e ++){
        for(int j = 0 ; j < m; j++){
            if(grid[e][j] == '.' && !isVisited[e][j]){
                sizeComponent = 0;
                dfs2(e,j);
                ans.pb({sizeComponent, numComponent});
                numComponent++;
            }
        }
    }
    sort(all(ans));
    // for(auto [x,y]: ans){
    //     cout << x << " " << y << endl;
    // }cout << endl;

    int deletes = ans.size() - k;
    int answer = 0;
    for(int e = 0 ; e < deletes;e++){
        answer += ans[e].first;
    }
    cout << answer << endl;
    for(int e = 0 ; e < deletes;e++){
        for(int j = 0 ; j < n; j++){
            for(int k = 0 ; k < m; k++){
                if(idComponent[j][k] == ans[e].second){
                    grid[j][k] = '*';
                }
            }
        }
    }
    // print
    for(int e = 0 ; e < n; e++){
        for(int j = 0 ; j < m; j++){
            cout << grid[e][j];
        }cout << endl;
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