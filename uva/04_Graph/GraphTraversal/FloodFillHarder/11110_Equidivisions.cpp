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
// 17:35
int n;
const int N = 100;
int grid[N][N];
bool isVisited[N][N];
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};
int ai,aj;
bool flag;
string str;
bool isValidPosition(int x, int y){
	return x>=0 && x<n && y>=0 && y<n;
}
void dfs(int x, int y){
	if(isVisited[x][y]) return;
	isVisited[x][y] = true;
	for(int e =0  ; e< 4; e++){
		int new_x = x + dx[e];
		int new_y = y + dy[e];
		if(isValidPosition(new_x,new_y) && grid[new_x][new_y] == grid[x][y]){
			dfs(new_x,new_y);
		}
	}
}
void solve(){
	while(1){
		cin>>n;
		cin.ignore();
		if(n == 0) break;
		else{
			// cout <<"else" << endl;
			// cout << "n: " << n << endl;
			if(n==1){
				cout << "good" << endl;
				continue;
			}
			for(int e = 0 ; e < n; e++){
				for(int j = 0 ; j < n; j++){
					isVisited[e][j] = false;
					grid[e][j] = 0;
				}
			}
			for(int e = 0 ; e < n-1; e++){
				// for(int j = 0 ; j < n; j++){
				// 	cin>>ai>>aj;
				// 	ai--;aj--;
				// 	grid[ai][aj] = e+1;
				// }
				getline(cin,str);
				stringstream ss(str);
				while(ss >> ai >> aj){
					ai--;aj--;
					grid[ai][aj] = e+1;
				}
				
			}
			// print grid
			// cout << endl;
			// cout << "print grid" << endl;
 			// for(int i = 0 ; i < n; i++){
			// 	for(int j = 0 ; j < n; j++){
			// 		cout << grid[i][j] << " ";
			// 	}
			// 	cout << endl;
			// }cout << endl;
			flag = false;
			map<int,int> mapa;
			for(int e = 0 ; e < n; e++){
				for(int j = 0 ;j < n ; j++){
					if(!isVisited[e][j]){
						dfs(e,j);
						mapa[grid[e][j]]++;
					}
				}
			}
			// recorrer el mapa para responder la pregunta
			// print mapa
			// cout << "mapa: " << endl;
			// for(auto e: mapa){
			// 	cout << e.first << " " << e.second << endl;
			// }cout << endl;

			for(auto e: mapa){
				if(e.second != 1){
					cout << "wrong" << endl;
					flag = true;
					break;
				}
			}
			if(!flag) cout << "good" << endl;

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