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
const int N = 1e3;
int grid[N][N];
bool isVisited[N][N];
int total;
int idx[] = {0,-1,0,1};
int idy[] = {1,0,-1,0};
int n,m;

bool isValidPosition(int x, int y){
	if(0 <= x && x < n && 0 <= y && y < m) return true;
	return false;
}

void dfs(int x, int y){
	if(grid[x][y] == 0) return;
	if(isVisited[x][y]) return;
	// cout << "x: " << x << " y: " << y << endl;
	isVisited[x][y]= true;
	total += grid[x][y];
	for(int e = 0 ; e < 4; e++){
		int new_x = x + idx[e];
		int new_y = y + idy[e];
		if(isValidPosition(new_x,new_y)){
			dfs(new_x,new_y);
		}
	}

}


void solve(){
	cin>>n>>m;
	for(int e = 0 ;e < n ; e++){
		for(int j = 0 ; j < m; j++){
			cin>>grid[e][j];
			isVisited[e][j] = false;
		}
	}
	// print grid
	// for(int e = 0 ;e < n ; e++){
	// 	for(int j = 0 ; j < m; j++){
	// 		cout << grid[e][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	total = 0;
	vector<int> ans;
	for(int e = 0 ; e < n; e++){
		for(int j = 0 ; j < m; j++){
			if(!isVisited[e][j]){
				dfs(e,j);
				if(total != 0)ans.pb(total);
				total = 0;
			}
		}
	}
	// for(auto e: ans){
	// 	cout << e << " ";	
	// }cout << endl;
	if(ans.size() == 0){
		cout << 0 << endl;
	}else{
		auto maximo = max_element(all(ans));
		cout << *maximo << endl;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifdef DEBUG
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t; cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}