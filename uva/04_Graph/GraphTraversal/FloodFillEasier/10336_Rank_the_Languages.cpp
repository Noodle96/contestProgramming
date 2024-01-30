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
char grid[N][N];
bool isVisited[N][N];
int H,W;
string str;

int idx[] = {0,-1,0,1};
int idy[] = {1,0,-1,0};

bool isValidPosition(int x, int y){
	if(0 <= x && x< H && 0 <=y && y< W) return true;
	return false;
}

void dfs(int x, int y){
	if(isVisited[x][y]) return;
	isVisited[x][y] = true;
	for(int e = 0 ; e < 4; e++){
		int new_x = x + idx[e];
		int new_y = y + idy[e];
		if(isValidPosition(new_x,new_y) && grid[new_x][new_y] == grid[x][y]){
			dfs(new_x,new_y);
		}
	}
}

void solve(int caso){
	cin>>H>>W;
	for(int e = 0 ; e < H; e++){
		cin>>str;
		for(int j = 0 ; j < (int)str.size(); j++){
			grid[e][j] = str[j];
			isVisited[e][j] = false;
		}
	}
	map<char, int> map;
	for(int e = 0 ; e < H; e++){
		for(int j = 0 ; j < W; j++){
			if(!isVisited[e][j]){
				dfs(e,j);
				map[grid[e][j]]++;
			}
		}
	}
	cout << "World #" << caso << endl;
	vector<pair<int,char>> vec;
	for(auto e: map){
		vec.pb({e.second,e.first});
	}
	sort(vec.begin(), vec.end(),[](pair<int,char> &a, pair<int,char> &b){
		if(a.first == b.first) return a.second < b.second;
		return a.first > b.first;
	});
	for(auto e: vec){
		cout << e.second << ": " << e.first << endl;
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
	int caso = 1;
	while(t--){
		solve(caso++);
	}
	
	return 0;
}