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
const int N = 100;
int n,m;
char grid[N][N];
bool isVisited[N][N];
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};

bool isValidPosition(int x, int y){
	if(0 <= x && x < n && 0 <= y && y < m) return true;
	return false;
}

void dfs(int x, int y){
	if(isVisited[x][y]) return;
	isVisited[x][y] = true;
	if(grid[x][y] == '.')grid[x][y] = 'B';
	for(int e = 0 ; e < 4; e++){
		int new_x = x + dx[e];
		int new_y = y + dy[e];
		if(isValidPosition(new_x, new_y) && grid[new_x][new_y] == '.'){
			grid[new_x][new_y] = (grid[x][y] == 'B') ? 'W' : 'B';
			dfs(new_x, new_y);
		}
	}
}
void solve(){
	cin>>n>>m;
	for(int e = 0 ; e < n; e++){
		for(int j = 0 ; j < m; j++){
			cin>> grid[e][j];
			isVisited[e][j] = false;
		}
	}
	// print grid
	// for(int e = 0 ; e < n; e++){
	// 	for(int j = 0 ; j < m; j++){
	// 		cout << grid[e][j] << " ";
	// 	}cout << endl;
	// }cout << endl;
	// bool flag = true;
	
	
	// for( ; e < n; e++){
	// 	for( ; j < m; j++){
	// 		if(grid[e][j]=='.'){
	// 			grid[e][j] = 'B';
	// 			flag = false;
	// 			break;
	// 		}
	// 	}
	// 	if(flag == false) break;
	// }

	for(int e = 0; e < n; e++){
		for(int j = 0; j < m; j++){
			if(grid[e][j] == '.'){
				dfs(e,j);
			}
		}
	}
	for(int e = 0 ; e < n; e++){
		for(int j = 0 ; j < m; j++){
			cout << grid[e][j];
		}cout << endl;
	}cout << endl;

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