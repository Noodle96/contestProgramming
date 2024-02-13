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
const int N = 50;
int n,m;
int group;
char grid[N][N];
bool isVisited[N][N];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
vector<pair<int,int>> spots[2];

bool isValidPosition(int x, int y){
	if(0 <= x && x < n && 0<=y && y < m) return true;
	return false;
}

void dfs(int x , int y){
	if(isVisited[x][y])return;
	isVisited[x][y] = true;
	spots[group].pb({x,y});
	for(int e = 0; e < 4 ;e++){
		int new_x  = x + dx[e];
		int new_y = y + dy[e];
		if(isValidPosition(new_x,new_y) && grid[new_x][new_y] == 'X'){
			dfs(new_x,new_y);
		}
	}

}

void solve(){
	cin>>n>>m;
	for(int e = 0 ;e < n ;e++){
		for(int j = 0 ; j < m; j++){
			cin>>grid[e][j];
			isVisited[e][j] = false;
		}
	}
	// print grid
	// for(int e = 0 ;e < n ;e++){
	// 	for(int j = 0 ; j < m; j++){
	// 		cout << grid[e][j];
	// 	}
	// 	cout << endl;
	// }cout << endl;
	group = 0;
	for(int e = 0 ;e < n ;e++){
		for(int j = 0 ; j < m; j++){
			if(grid[e][j] == 'X' && !isVisited[e][j]){
				dfs(e,j);
				group++;

			}
		}
	}
	// for(int e = 0 ; e < 2; e++){
	// 	cout << "spot: " << e << endl;
	// 	for(auto it : spots[e]){
	// 		cout << it.first << " " << it.second << endl;
	// 	}
	// }
	int ans = 1e9;
	for(int e = 0 ; e < spots[0].size(); e++){
		for(int j = 0 ; j < spots[1].size(); j++){
			int x1 = spots[0][e].first;
			int y1 = spots[0][e].second;
			int x2 = spots[1][j].first;
			int y2 = spots[1][j].second;
			ans = min(ans,abs(x1-x2) + abs(y1-y2) - 1);
		}
	}
	cout << ans << endl;
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