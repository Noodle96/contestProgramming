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
string str;
int a,b;
int r;
int c;
int cont;
int idx[] = {0,-1,-1,-1,0,1,1,1};
int idy[] = {1,1,0,-1,-1,-1,0,1};

bool isValidPosition(int x, int y){
	if(0 <= x && x < r && 0 <= y && y < c) return true;
	return false;
}

void dfs(int x, int y){
	if(isVisited[x][y]) return;
	isVisited[x][y] = true;
	cont++;
	// cout << "x: " << x << " y: " << y << endl;
	for(int e = 0 ;e < 8 ; e++){
		int new_x = x + idx[e];
		int new_y = y + idy[e];
		if(isValidPosition(new_x,new_y) && grid[new_x][new_y] == 'W'){
			dfs(new_x,new_y);
		}
	}
}
void solve(){
	r = 0;
	while(1){
		getline(cin,str);
		if(str[0] == 'W' || str[0] == 'L'){
			for(int e = 0 ; e < (int)str.size(); e++){
				grid[r][e] = str[e];
				isVisited[r][e] = false;
			}
			r++;
			c = (int)str.size();
		}else break;
	}
	//print grid
	// cout << "grid: " << endl;
	// for(int e = 0 ; e < r; e++){
	// 	for(int j = 0 ; j < c; j++){
	// 		cout << grid[e][j];
	// 	}
	// 	cout << endl;
	// }cout << endl;
	istringstream iss(str);
	iss>>a>>b;
	vector<pii> points;
	points.pb({a-1,b-1});
	// cout << "pair: "<< a <<" " << b << endl;
	while(1){
		getline(cin,str);
		if(str.size() == 0) break;
		else{
			// cout << "pair: "<<str << endl;
			istringstream is2(str);
			is2>>a>>b;
			points.pb({a-1,b-1});
		}
	}
	// print points
	// cout << "points: " << endl;
	// for(auto e: points){
	// 	cout << e.first << " " << e.second << endl;
	// }cout << endl;
	for(auto e: points){
		int x = e.first;
		int y = e.second;
		if(!isVisited[x][y]){ // only water
			cont = 0;
			dfs(x,y);
			cout << cont << endl;
			// set false all visited
			for(int e = 0 ; e < r; e++){
				for(int j = 0 ; j < c; j++){
					isVisited[e][j] = false;
				}
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
	string s;
	int t; cin>>t;
	getline(cin,s);
	cin.ignore();
	while(t--){
		solve();
		if(t>0) cout << endl;
	}
	
	return 0;
}