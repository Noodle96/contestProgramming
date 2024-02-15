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
const int N = 10;
char cube[N][N][N];
bool isVisited[N][N][N];
int k,n,m;
int x,y;
string str;
// int dx[] = {0,-1,0,1};
// int dy[] = {1,0,-1,0};
// int dz[] = {1,-1};
int dx[] = {0, 0, 1, -1, 0, 0};
int dy[] = {1, -1, 0, 0, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
int cont;
bool isValidPosition(int z, int x, int y){
	if(z < 0 || z >= k) return false;
	if(y < 0 || y >= n) return false;
	if(x < 0 || x >= m) return false;
	return true;

}

void dfs(int z, int x, int y){
	if(isVisited[z][x][y]) return;
	isVisited[z][x][y] = true;
	// cout << "val: " << cube[z][x][y] << endl;
	// cout << "z: " << z << " x: " << x << " y: " << y << endl;
	cont++;
	for(int i = 0 ; i < 6; i++){
		int new_x = x + dx[i];
		int new_y = y + dy[i];
		int new_z = z + dz[i];
		// cout << "new_z: " << new_z << " new_x: " << new_x << " new_y: " << new_y << endl;
		if(isValidPosition(new_z, new_x, new_y) && cube[new_z][new_x][new_y] == '.'){
			dfs(new_z,new_x,new_y);
		}
	}
}

void solve(){
	cin>>k>>m>>n;
	cin.ignore();
	for(int capa= 0 ; capa < k; capa++){
		getline(cin,str);
		for(int e = 0 ; e < m; e++){
			for(int j = 0 ; j < n; j++){
				cin>>cube[capa][e][j];
				isVisited[capa][e][j] = false;
			}
		}
	}
	// print cube
	// cout << "print cube" << endl;
	// for(int capa= 0 ; capa < k; capa++){
	// 	cout << "capa: " << capa<<endl;
	// 	for(int e = 0 ; e < m; e++){
	// 		for(int j = 0 ; j < n; j++){
	// 			cout << cube[capa][e][j];
	// 		}cout << endl;
	// 	}cout << endl << endl;
	// }
	getline(cin,str);
	cin>>y>>x;
	x--;y--;
	cont = 0;
	dfs(0,y,x);
	cout << cont << endl;
	// cout << "x: " << x <<" y: " << y << endl;

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