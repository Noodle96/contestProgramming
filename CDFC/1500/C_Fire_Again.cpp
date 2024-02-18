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

const int N = 2e3;
const int INF = 1e9;
int n,m,k;
int a,b;
int grid[N][N];
bool isVisited[N][N];
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};
vector<pair<int,int>> start;

bool isValidPosition(int x,int y ){
	if(0<= x && x < n && 0 <= y && y < m) return true;
	return false;
}
void resetIsValid(){
	for(int e = 0 ; e < N; e++){
		for(int j = 0 ; j < N; j++){
			isVisited[e][j] = false;
		}
	}
}

void BFS(int x, int y){
	queue<pii> q;
	q.push({x,y});
	isVisited[x][y] = true;
	grid[x][y] = 0;

	while(!q.empty()){
		auto pair = q.front();
		int cur_x = pair.first;
		int cur_y = pair.second;
		q.pop();
		for(int e = 0 ; e < 4; e++){
			int new_x = pair.first + dx[e];
			int new_y = pair.second + dy[e];
			if(isValidPosition(new_x, new_y) && !isVisited[new_x][new_y]){
				grid[new_x][new_y] = min(1 + grid[cur_x][cur_y], grid[new_x][new_y]);
				q.push({new_x,new_y});
				isVisited[new_x][new_y] = true;
			}
		}
	}

}



void solve(){
	// for(int e = 0 ; e < 10; e++){
	// 	for(int j = 0 ; j < 10; j++){
	// 		cout << grid[e][j] << " ";
	// 	}cout << endl;
	// }cout << endl;
	for(int e = 0 ; e < N; e++){
		for(int j = 0 ; j < N; j++){
			grid[e][j] = INF;
			isVisited[e][j] = false;
		}
	}
	cin>>n>>m>>k;
	for(int e = 0 ;e < k ; e++){
		cin>>a>>b;
		a--,b--;
		start.pb({a,b});
	}
	// cout << "print grid: " << endl;
	// for(int e = 0 ; e < n; e++){
	// 	for(int j = 0 ; j < m; j++){
	// 		cout << grid[e][j] << " ";
	// 	}cout << endl;
	// }cout << endl;
	for(int e = 0 ; e < start.size(); e++){
		BFS(start[e].first,start[e].second);
		resetIsValid();
		// cout << "print grid: " << endl;
		// for(int e = 0 ; e < n; e++){
		// 	for(int j = 0 ; j < m; j++){
		// 		cout << grid[e][j] << " ";
		// 	}cout << endl;
		// }cout << endl;
	}
	pair<int,int> ans = {0,0};
	int max = INT_MIN;
	for(int e = 0 ; e < n; e++){
		for(int j = 0 ; j < m; j++){
			if(grid[e][j] > max){
				max = grid[e][j];
				ans = {e,j};
			}
		}
	}
	cout << ans.first + 1 << " " << ans.second + 1 << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	// #ifdef DEBUG
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	// #endif
	solve();
	return 0;
}