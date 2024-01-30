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
const int N = 101;
char grid[N][N];
bool isVisited[N][N];
int r,c;
int idx[] = {0,-1,-1,-1,0,1,1,1};
int idy[] = {1,1,0,-1,-1,-1,0,1};
string str;
int cont, starts;
bool isValidPosition(int x, int y){
	if(0 <= x && x< r && 0 <=y && y< c) return true;
	return false;
}
void dfs(int x, int y){
	if(isVisited[x][y]) return;
	isVisited[x][y] = true;
	cont++;
	for(int e = 0 ; e < 8; e++){
		int new_x = x + idx[e];
		int new_y = y + idy[e];
		if(isValidPosition(new_x,new_y) && grid[new_x][new_y] == '*'){
			dfs(new_x,new_y);
		}
	}
}

void solve(){
	while(cin>>r>>c){
		if(r == 0 && c == 0) break;
		else{
			starts = 0;
			for(int e = 0 ; e < r; e++){
				cin>>str;
				for(int j = 0 ; j < (int)str.size(); j++){
					grid[e][j] = str[j];
					isVisited[e][j] = false;
				}
			}
			for(int e = 0 ; e < r; e++){
				for(int j = 0 ; j < (int)str.size(); j++){
					if(!isVisited[e][j] && grid[e][j] == '*'){
						cont = 0;
						dfs(e,j);
						if(cont == 1) starts++;
					}
				}
			}
			cout << starts << endl;
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