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
char grid[N][N];
bool isVisited[N][N];
int n;
string str;
bool isValidPosition(int x, int y){
	return x >= 0 && x < n && y >= 0 && y < n;
}

void travelRight(int x, int y){
	if(isVisited[x][y]) return ;
	str += grid[x][y];
	isVisited[x][y] = true;
	if(isValidPosition(x,y+1) && (grid[x][y+1] == 'x' || grid[x][y+1] == '@')){
		travelRight(x,y+1);
	}
}
void travelDown(int x, int y){
	if(isVisited[x][y]) return;
	str += grid[x][y];
	isVisited[x][y] = true;
	if(isValidPosition(x+1,y) && (grid[x+1][y] == 'x' || grid[x+1][y] == '@')){
		travelDown(x+1,y);
	}
}

void dfs(int x, int y){
	if(isVisited[x][y]) return;
	str += grid[x][y];
	isVisited[x][y] = true;
	if(isValidPosition(x,y+1) && (grid[x][y+1] == 'x' || grid[x][y+1] == '@')){
		travelRight(x,y+1);
	}else if(isValidPosition(x+1,y) && (grid[x+1][y] == 'x' || grid[x+1][y] == '@')){
		travelDown(x+1,y);
	}else{
		;
	}
}
bool isValidPath(string str){
	for(int e = 0 ; e < (int)str.size(); e++){
		if(str[e] == 'x') return true;
	}
	return false;
}
void solve(int caso){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>grid[i][j];
			isVisited[i][j] = false;
		}
	}
	// print grid
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<n;j++){
	// 		cout << grid[i][j];
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;
	int ans = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(!isVisited[i][j]  && grid[i][j] != '.'){
				str = "";
				dfs(i,j);
				if(isValidPath(str)) ans++;
				// cout <<"path: " << str << endl;
			}
		}
	}
	cout << "Case " << caso << ": "<< ans << endl;

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifdef DEBUG
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t; cin>>t;
	int caso = 1;
	while(t--){
		solve(caso++);
	}
	
	return 0;
}