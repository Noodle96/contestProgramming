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
const int N = 50;
char grid[N][N];
bool isVisited[N][N];
int n;
int r1,c1,r2,c2;
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};
vector<pii> group[N*N];
int gr;
int cantidadGrupos;

bool isValidPosition(int x, int y){
	if(x < 0 || x >= n) return false;
	if(y < 0 || y >= n) return false;
	return true;
}

void dfs(int x, int y){
	if(isVisited[x][y]) return;
	isVisited[x][y] = true;
	group[gr].pb({x,y});
	for(int i = 0 ; i < 4; i++){
		int new_x = x + dx[i];
		int new_y = y + dy[i];
		if(isValidPosition(new_x,new_y) && grid[new_x][new_y] == '0'){
			dfs(new_x,new_y);
		}
	}
}

void solve(){
	cantidadGrupos = 0;
	cin>>n;
	cin>>r1>>c1>>r2>>c2;
	r1--;c1--;r2--;c2--;
	for(int e = 0 ; e < n ; e++){
		for(int j = 0 ; j < n; j++){
			cin>>grid[e][j];
		}
	}
	// print grid
	// for(int e = 0 ; e < n ; e++){
	// 	for(int j = 0 ; j < n; j++){
	// 		cout << grid[e][j];
	// 	}
	// 	cout << endl;
	// }cout << endl;
	gr = 0;
	dfs(r1,c1);
	cantidadGrupos++;

	gr = N*N-1;
	dfs(r2,c2);
	if(group[N*N-1].size() == 0){
		cout << 0 << endl; return;
	}
	cantidadGrupos++;


	gr = 1;
	for(int e = 0 ; e < n; e++){
		for(int j = 0 ; j < n; j++){
			if(!isVisited[e][j] && grid[e][j] == '0'){
				dfs(e,j);
				gr++;
				cantidadGrupos++;
			}
		}
	}
	group[cantidadGrupos-1] = group[N*N-1];
	// for(int e =0 ; e < cantidadGrupos; e++){
	// 	cout << "grupo: " << e << endl;
	// 	for(auto e: group[e]){
	// 		cout << e.first << " " << e.second << endl;
	// 	}
	// }
	vector< vector<int> > matriz(cantidadGrupos,vector<int>(cantidadGrupos,1e9));
	int minimo = 1e9;
	if(cantidadGrupos >= 2){
		for(int grupo = 0 ; grupo < cantidadGrupos; grupo++){
			for(int nextGrupo = grupo+1; nextGrupo < cantidadGrupos; nextGrupo++){
				// cout << "grupo "  << grupo << " con nextGrupo " << nextGrupo << endl;
				minimo = 1e9;
				for(auto e: group[grupo]){
					for(auto j: group[nextGrupo]){
						int x = e.first;
						int y = e.second;
						int x2 = j.first;
						int y2 = j.second;
						int dist = (x-x2)*(x-x2) + (y-y2)*(y-y2);
						// cout << x << " " << y << " " << x2 << " " << y2 << " dist: " << dist << endl;
						minimo = min(minimo,dist);
					}
				}
				matriz[grupo][nextGrupo] = minimo;
				matriz[nextGrupo][grupo] = minimo;
			}
		}
		// for(int e = 0 ;e < matriz.size() ; e++){
		// 	for(int j = 0 ; j < matriz.size(); j++){
		// 		if(e == j) matriz[e][j] = 0;
		// 	}
		// }
		//print matriz
		// for(int e = 0 ; e < cantidadGrupos; e++){
		// 	for(int j = 0 ; j < cantidadGrupos; j++){
		// 		cout << matriz[e][j] << " ";
		// 	}cout << endl;
		// }cout << endl;


		//floyd warshall
		// int n = matriz.size();
		// for(int k = 0; k < n ; k++){
		// 	for(int i = 0 ;i < n ; i++){
		// 		for(int j = 0 ;j < n ; j++){
		// 			matriz[i][j] = min(matriz[i][j],matriz[i][k]+matriz[k][j]);
		// 		}
		// 	}
		// }

		//print matriz
		// cout << "matriz final" << endl;
		// for(int e = 0 ; e < cantidadGrupos; e++){
		// 	for(int j = 0 ; j < cantidadGrupos; j++){
		// 		cout << matriz[e][j] << " ";
		// 	}cout << endl;
		// }cout << endl;
		//print answer
		cout << matriz[0][cantidadGrupos-1];

	}else{
		//un solo grupo
		// cout << 0 << endl;
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