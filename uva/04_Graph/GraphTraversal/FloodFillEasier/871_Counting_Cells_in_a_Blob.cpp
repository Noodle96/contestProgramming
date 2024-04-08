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
string line;
int r,c;
const int N = 25;
char grid[N][N];
int maxLen;
bool isVisited[N][N];
int dx[] = {0,0,1,-1,1,-1,1,-1};
int dy[] = {1,-1,0,0,1,-1,-1,1};

bool isValidPosition(int x, int y){
	return x >= 0 && x < r && y >= 0 && y < c;
}

void floodFill(int x, int y){
	if(isVisited[x][y] ) return;
	maxLen++;
	isVisited[x][y] = true;
	for(int e = 0 ; e < 8; e++){
		int new_x = x + dx[e];
		int new_y = y + dy[e];
		if(isValidPosition(new_x, new_y) && grid[new_x][new_y]=='1'){
			floodFill(new_x,new_y);
		}
	}
}

void solve(){
	getline(cin,line);
	// cin>>line;
	// cout << "line1: " << line << endl;
	c = line.size();
	// cout << "c: " << c << endl;
	r = 0;
	for(int e = 0 ; e < c;e++){
		grid[r][e] = line[e];
		isVisited[r][e] = false;
	}
	r++;
	while(getline(cin,line)){
		// cout << "line2: " << line << endl;
		if(line.size() == 0) break;
		for(int i = 0 ; i < c ; i++){
			grid[r][i] = line[i];
			isVisited[r][i] = false;
		}
		r++;
	}
	// cout << "print grid\n";
	// for(int e = 0 ; e <r; e++){
	// 	for(int j = 0 ; j < c; j++){
	// 		cout << grid[e][j];
	// 	}cout << endl;
	// }cout << endl;

	int maximo = 0;
	for(int e = 0 ; e <r; e++){
		for(int j = 0 ; j < c; j++){
			if(!isVisited[e][j] && grid[e][j]=='1'){
				maxLen = 0;
				floodFill(e,j);
				maximo = max(maximo,maxLen);
			}

		}
	}
	cout << maximo << endl;
}
// void solve2(){
// 	while(getline(cin,line)){
// 		cout << "line1: " << line << endl;
// 	}
// 	cout << "end" << endl;
// }
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifdef DEBUG
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t; cin>>t;
	cin.ignore();
	getline(cin,line);
	// cout << "line: [" << line << "]" << endl;
	while(t--){
		solve();
		if(t) cout << endl;
	}
	// solve2();
	return 0;
}