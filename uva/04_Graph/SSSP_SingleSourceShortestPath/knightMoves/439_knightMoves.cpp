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

const int INF = 1e9;
const int N = 8;
const int dx[] = {1,-1, 1,-1,2,2,-2,-2};
const int dy[] = {2,2,-2,-2,1,-1,1,-1};
bool isVisited[N][N];
string inicio, finall;
int ans;
bool isValidPosition(int x, int y){
    return x >= 0 && x < N && y >= 0 && y < N;
}

void floodFill(int x, int y, int paso){
    if(isVisited[x][y]) return;
    isVisited[x][y] = true;
    if(x == finall[1] - '1' && y == finall[0] - 'a'){
        cout << "entro con: " <<paso <<  endl;
        // return;
        ans = min(ans, paso);
    }
    for(int e = 0 ; e < 8; e++){
        int new_x = x + dx[e];
        int new_y = y + dy[e];
        if(isValidPosition(new_x, new_y)){
            floodFill(new_x, new_y, paso + 1);
        }
    }
}


void solve(){
    // fillGrid();
    while(cin>>inicio>>finall){
        // cout << "inicio: " << inicio << " finall: " << finall << endl;
        memset(isVisited, false, sizeof isVisited);
        int x = inicio[1] - '1';
        int y = inicio[0] - 'a';

        //BFS implementation
        queue<pair<int,int>> q;
        q.push({x,y});
        isVisited[x][y] = true;
        int level = 0;
        while(!q.empty()){
            int sz = q.size();
            bool flag = false;
            for(int i = 0 ; i < sz; i++){
                pair<int,int> current = q.front(); q.pop();
                if(current.first == finall[1] - '1' && current.second == finall[0] - 'a'){
                    cout << "To get from " << inicio << " to " << finall << " takes " << level << " knight moves." << endl;
                    flag = true;
                    break;
                }
                for(int e = 0 ; e < 8; e++){
                    int new_x = current.first + dx[e];
                    int new_y = current.second + dy[e];
                    if(isValidPosition(new_x, new_y) && !isVisited[new_x][new_y]){
                        q.push({new_x, new_y});
                        isVisited[new_x][new_y] = true;
                    }
                }
            }
            if(flag) break;
            level++;
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
