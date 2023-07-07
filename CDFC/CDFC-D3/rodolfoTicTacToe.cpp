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

const int N = 4;
char grid[N][N];
bool isVisited[N][N];
int maximo;
// int dx[] ={1,1,0,-1,-1,-1,0,1};
// int dy[] ={0,1,1,1,0,-1,-1,-1};
int dx[] ={1,1,1,0};
int dy[] ={-1,0,1,1};
			// abc
			// efg
			// hij

bool isValidPosition(int row, int col){
	if(row < 0 || row >=3 || col < 0 || col >=3) return false;
	return true;
}

bool dfs(int current_row, int current_col, int lenght = 1){
	// cout << current_row << " " <<  current_col << endl;
	// if(isVisited[current_row][current_col]) return false;
	// isVisited[current_row][current_col] = true;
	// maximo = max(maximo,lenght);

	// msg("maximo: ",maximo);
	int temp_row, temp_col;
	for(int e = 0 ; e < 4 ;e++){
		temp_row = current_row + dx[e];
		temp_col = current_col + dy[e];
		if(isValidPosition(temp_row, temp_col)){
			if(grid[current_row][current_col] == grid[temp_row][temp_col]){	
				if(isValidPosition(temp_row+dx[e], temp_col + dy[e])){
					if(grid[temp_row+dx[e]][temp_col + dy[e]] == grid[temp_row][temp_col]) return true;
				}
				// if(dfs(temp_row, temp_col, lenght+1)) return true;
			}
		}
	}
	return false;
}


void solve(){
	for(int e = 0 ;e < 3 ; e++)
		for(int j = 0  ;j < 3 ; j++)
			cin>> grid[e][j];

	// for(int e = 0 ;e < 3 ; e++)
	// 	for(int j = 0  ;j < 3 ; j++)
	// 		isVisited[e][j] = 0;

	for(int e = 0 ;e < 3 ; e++){
		for(int j = 0  ;j < 3 ; j++){
			// maximo  = 0;
			if(grid[e][j] != '.'){
				if(dfs(e,j)){
					// cout << "msg: " << endl;
					msg(grid[e][j],"");
					return;
				}
			}
		}
	}
	msg("DRAW","");
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