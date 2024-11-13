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

int r,c;
const int N = 50;
char grid[N][N];
bool isVisited[N][N];
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};
int cont;


bool isValidPosition(int x, int y){
	return x>=0 && x<r && y>=0 && y<c;
}

void dfs(int x, int y){
	if(isVisited[x][y]) return;
	cont++;
	isVisited[x][y] = true;
	for(int e = 0 ; e < 8; e++){
		int new_x = x + dx[e];
		int new_y = y + dy[e];
		if(isValidPosition(new_x, new_y) && grid[new_x][new_y] == grid[x][y]){
			dfs(new_x,new_y);
		}
	}
}


void solve(){
	int caso = 1;
	while(1){
		cin>>r>>c;
		if(r == 0 && c==0) break;
		else{
			//fill grid
			for(int i=0;i<r;i++){
				for(int j=0;j<c;j++){
					cin>>grid[i][j];
					isVisited[i][j] = false;
				}
			}
			vector<pair<char,int>> ans;
			for(int i=0;i<r;i++){
				for(int j=0;j<c;j++){
					if(!isVisited[i][j] && grid[i][j] != '.'){
						cont = 0;
						dfs(i,j);
						ans.pb({grid[i][j],cont});
					}
				}
			}
			//print ans
			sort(ans.begin(), ans.end(), [](pair<char,int> &a, pair<char,int> &b){
				if(a.second == b.second) return a.first < b.first;
				else return a.second > b.second;
			});
			cout << "Problem " << caso++  << ":" << endl;
			for(auto e: ans){
				cout<<e.first<<" "<<e.second<<endl;
			}
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