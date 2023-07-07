#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define msg(str,str2) cout << str << str2<< endl
using namespace std;

// using ll = long long;
// using ld = long double;
// using uint = unsigned int;
// using ull = unsigned long long;
// template<typename T>
// using pair2 = pair<T, T>;
// using pii = pair<int, int>;
// using pli = pair<ll, int>;
// using pll = pair<ll, ll>;
// using vvb = vector<vector<bool>>;
// using vvc = vector<vector<char>>;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

//		a b c
//		d E f
//		g h i
//variations directions
int d_row[] =     {1,1,0,-1,-1,-1,0,1};
int d_column[] = {0,1,1,1,0,-1,-1,-1};

int H,W;
int k = 0;
vector< vector<char> > grid;
vector< vector<bool> > visited;
int maxPathLen = 0;

bool isValidPosition(int curr_row, int curr_col){
	// msg("W: ", W );
	if(curr_row < 0 || curr_row >=H || curr_col < 0 || curr_col >= W) return false;
	return true;
}

void dfs(int row, int col, int length = 1)	{
	if(visited[row][col]) return;
	visited[row][col] = true;
	maxPathLen = max(maxPathLen,length);
	int temp_row, temp_col;
	for(int i = 0 ;i < 8 ; i++){
		temp_row = row + d_row[i];
		temp_col = col + d_column[i];
		if(isValidPosition(temp_row,temp_col)){
			if(grid[temp_row][temp_col] - grid[row][col] == 1) dfs(temp_row,temp_col,length+1);
		}
	}

}

void solve(){
	while(cin>>H>>W){
		if(!H && !W) break;
		grid.clear(); grid.resize(H, vector<char>(W));
		visited.clear(); visited.resize(H, vector<bool>(W));
		// for(int e = 0 ;e < H ; e++){
		// 	for(int j = 0 ; j < W; j++){
		// 		cout << visited[e][j] << " ";
		// 	}cout << endl;
		// }
		// cout << endl;
		// return;
		for(int row = 0 ; row < H; row++)
			for(int col = 0 ;  col < W; col++ )
				cin>>grid[row][col];
		for(int row = 0 ; row < H; row++)
			for(int col = 0 ;  col < W; col++ )
				visited[row][col] = 0;

		for(int row = 0 ;row < H ; row++){
			for(int col =0 ; col < W; col++){
				if(grid[row][col] == 'A') dfs(row,col);
			}
		}
		cout << "Case " << ++k << ": " << maxPathLen << endl;
		maxPathLen = 0;
		// msg("print grid: ","");
		// for(auto it = grid.begin()  ;it != grid.end() ; it++){
		// 	for(auto et = it->begin(); et != it->end() ; et++){
		// 		cout << *et << " ";
		// 	}cout << endl;
		// }
		// cout << endl;
		// msg("print visited: ","");
		// for(auto it = visited.begin()  ;it != visited.end() ; it++){
		// 	for(auto et = it->begin(); et != it->end() ; et++){
		// 		cout << *et << " ";
		// 	}cout << endl;
		// }

		
	}
}

int main(){
	solve();
	return 0;
}