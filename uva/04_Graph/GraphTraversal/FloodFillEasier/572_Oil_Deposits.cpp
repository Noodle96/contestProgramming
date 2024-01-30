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
int m,n;
const int N = 101;
char grid[N][N];
bool isVisited[N][N];
string str;
int idx[] = {0,-1,-1,-1,0,1,1,1};
int idy[] = {1,1,0,-1,-1,-1,0,1};

bool isValidPosition(int x, int y){
	if(0 <= x && x< m && 0 <=y && y< n) return true;
	return false;
}

void dfs(int x, int y){
	if(isVisited[x][y]) return;
	isVisited[x][y] = true;
	for(int e = 0 ; e < 8; e++){
		int new_x = x + idx[e];
		int new_y = y + idy[e];
		if(isValidPosition(new_x,new_y) && grid[new_x][new_y] == '@'){
			dfs(new_x,new_y);
		}
	}
}

void solve(){
	while(1){
		cin>>m>>n;
		if(m== 0) break;
		else{
			for(int e = 0 ; e < m; e++){
				cin>>str;
				for(int j = 0 ; j < (int)str.size() ; j++){
					grid[e][j] = str[j];
					isVisited[e][j] = false;
				}
			}
			int cont = 0;
			for(int e = 0 ; e < m; e++){
				for(int j = 0 ; j < n; j++){
					if(!isVisited[e][j] && grid[e][j] == '@'){
						dfs(e,j);
						cont++;
					}
				}
			}
			cout << cont << endl;
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