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
const int N = 35;
const int M = 85;
vector<vector<char>> grid;
bool isVisited[N][M];

const int dx[] = {0,0,1,-1,1,-1,1,-1};
const int dy[] = {1,-1,0,0,1,-1,-1,1};

bool containSub(string str){
    for(auto c: str) if(c=='_') return true;
    return false;
}

void dfs(int x, int y){
    if(isVisited[x][y]) return;
    isVisited[x][y] = true;
    grid[x][y] = '#';
    for(int e = 0 ; e < 8; e++){
        int new_x = x + dx[e];
        int new_y = y + dy[e];
        if(grid[new_x][new_y] == ' ') dfs(new_x,new_y);
    }
}
void solve(){
    int n; cin>>n;
    cin.ignore();
    string line;
    while(n--){
        grid.clear();
        memset(isVisited,0,sizeof(isVisited));
        while(getline(cin,line)){
            // cout << "line: " << line << endl;
            if(containSub(line)){
                break;
            }else{
                grid.pb(vector<char>(line.begin(),line.end()));
            }
        }
        // cout << "grid: " << n << endl;
        // for(auto it = grid.begin();it!=grid.end();it++){
        //     for(auto it2 = it->begin();it2!=it->end();it2++){
        //         cout << *it2;
        //     }
        //     cout << endl;
        // }cout << endl;
        int pos_x, pos_y;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='*'){
                    pos_x = i;
                    pos_y = j;
                    break;
                }
            }
        }
        dfs(pos_x, pos_y);
        // cout << "print grid: "<< endl;
        for(auto it = grid.begin();it!=grid.end();it++){
            for(auto it2 = it->begin();it2!=it->end();it2++){
                cout << *it2;
            }cout << endl;
        }cout <<line << endl;
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