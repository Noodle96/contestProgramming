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
#define fi first
#define se second

int dx[] = {1,1,0,-1,-1,-1,0,1};
int dy[] = {0,1,1,1,0,-1,-1,-1};

bool ans = false;
int n;
int cx,cy;
vector< vector<bool> > grid;
vector< vector<bool> > isVisited;

bool isValidPosition(int row, int col){
	if(row < 0 || row >=n || col < 0 || col >=n) return false;
	return true;
}

void dfs_fill(int row, int col, int varx, int vary){
	grid[row][col] = true;
	int new_row = row + varx;
	int new_col = col + vary;
	if( isValidPosition(new_row, new_col) ){
			dfs_fill(new_row, new_col, varx, vary);
	}
}


void fill_reds(int curr_row, int curr_col){
	//grid[curr_row][curr_col] = true;
	for(int e = 0 ; e < 8; e++){
		dfs_fill(curr_row, curr_col, dx[e], dy[e]);	
	}
}

// bool isValidPosition2(int x, int y){
// 	if(x < 0)
// } 

void dfs(int curr_row, int curr_col){
	if(isVisited[curr_row][curr_col]) return;
	isVisited[curr_row][curr_col] = true;
	if(grid[curr_row][curr_col] == true)return;
	if(curr_row == n-cy && curr_col == cx-1){
		ans = true; return;
	}
	for(int e = 0 ; e < 8; e++){
		int new_x = curr_row + dx[e];
		int new_y = curr_col + dy[e];
		if(isValidPosition(new_x, new_y)){
			dfs(new_x, new_y);
		}
	}

}

void solve(){
	// grid.clear();
	cin>>n;
	grid.resize(n, vector<bool>(n));
	isVisited.resize(n, vector<bool>(n));
	// for(int row = 0 ; row < n; row++){
	// 	for(int col = 0 ; col < n; col++){
	// 		cout << grid[row][col] << " ";
	// 	}cout << endl;
	// }cout << endl;
	int ax,ay, bx,by;
	cin>>ax>>ay>>bx>>by>>cx>>cy;
	fill_reds(n-ay,ax-1);
	// grid[n-by][bx-1] = true;
	// grid[n-cy][cx-1] = true;
	// for(int row = 0 ; row < n; row++){
	// 	for(int col = 0 ; col < n; col++){
	// 		cout << grid[row][col] << " ";
	// 	}cout << endl;
	// }cout << endl;

	dfs(n-by, bx-1);
	cout << (ans?"YES":"NO") << endl;

	return;
}

int main(){
	// #ifndef IN_OUT
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
	
	solve();
	return 0;
}