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

// abc
// efg	
// hij

int dx[] = {1,1,0,-1,-1,-1,0,1};
int dy[] = {0,1,1,1,0,-1,-1,-1};

int n;
vector<vector<char>> grid;
vector< vector<bool> > isVisited;
bool ans = false;

bool isValidPosition(int row, int col){
	if(row < 0 || row >= 2 || col < 0 || col >=n) return false;
	return true;
}

void dfs(int curr_row, int curr_col){
	// cout << "msg" << endl;
	// cout << curr_row << " " << curr_col << endl;
	// cout << "value: " << grid[curr_row][curr_col] << endl;


	if(isVisited[curr_row][curr_col]) return;
	isVisited[curr_row][curr_col] = true;


	if(grid[curr_row][curr_col] == '1' ) return ;

	

	if(curr_row == 1 & curr_col == n-1){
		// cout << "obj" << endl;
		ans = true;
		return;
	}

	for(int e = 0 ; e < 8; e++){
		int new_row = curr_row + dx[e];
		int new_col = curr_col + dy[e];
		if( isValidPosition(new_row, new_col) ){
			dfs(new_row, new_col);
		}
	}
}

void solve(){
	grid.clear();
	isVisited.clear();
	ans = false;
	cin>>n;
	// cout << "n: " << n << endl;
	grid.resize(2,vector<char>(n));
	isVisited.resize(2, vector<bool>(n));
	// msg("print grid inicial: ","");
	// for(int row = 0 ;row < 2 ; row++){
	// 	for(int col = 0 ; col < n;col++ ){
	// 		cout << grid[row][col] << " ";
	// 	}cout << endl;
	// }cout << endl;

	// msg("print isvisited  inicial: ","");
	// for(int row = 0 ;row < 2 ; row++){
	// 	for(int col = 0 ; col < n;col++ ){
	// 		cout << isVisited[row][col] << " ";
	// 	}cout << endl;
	// }cout << endl;

	
	for(int row = 0 ;row < 2 ; row++){
		for(int col = 0 ; col < n;col++ ){
			cin>>grid[row][col];
		}
	}
	// msg("print grid after :  ","");
	// for(int row = 0 ;row < 2 ; row++){
	// 	for(int col = 0 ; col < n;col++ ){
	// 		cout << grid[row][col] << " ";
	// 	}cout << endl;
	// }cout << endl; return;

	// msg("print isvisited  after: ","");
	// for(int row = 0 ;row < 2 ; row++){
	// 	for(int col = 0 ; col < n;col++ ){
	// 		cout << isVisited[row][col] << " ";
	// 	}cout << endl;
	// }cout << endl;
	// return;
	dfs(0,0);
	cout << (ans?"YES":"NO") << endl;
}
int main(){
	// #ifndef IN_OUT
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
	
	int t; cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}