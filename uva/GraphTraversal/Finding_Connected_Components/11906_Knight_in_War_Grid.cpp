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

int caso = 1, cont;
int R,C,M,N,Z;
vector< vector<bool> > grid;
vector< vector<bool> >isVisited;
vector<int> dx,dy;
vector<int> dx_zero, dy_zero;
queue<pair<int,int>> q;
int odd,even;

void setDimension(){
	int dx_[] = {M, M, -M, -M, N, N, -N, -N};
	int dy_[] = {N,-N, -N, N,  M, -M, -M, M };
	int dx_zero_[] = {0, 0, Z, -Z};
	int dy_zero_[] = {Z,-Z,0, 0};

	dx.assign(dx_, dx_+8);
	dy.assign(dy_, dy_+8);
	dx_zero.assign(dx_zero_, dx_zero_+4);
	dy_zero.assign(dy_zero_, dy_zero_+4);
	// for(int e = 0 ; e < 8; e++){
	// 	cout << dx[e] << " ";
	// }cout << endl;

	// for(int e = 0 ; e < 8; e++){
	// 	cout << dy[e] << " ";
	// }cout << endl;

}

// vector< vector<bool> > isVisited;
bool isValidPosition(int r, int c){
	if(r>= 0 && r < R && c>=0 && c < C && grid[r][c] == true) return true;
	return false;
}

int f_zero(int e, int j){
	// cout << "e: " << e << " j: " << j << endl; 
	int contador = 0;
	for(int i = 0 ; i < 4 ; i++){
		int new_e = e + dx_zero[i];
		int new_j = j + dy_zero[i];
		if( isValidPosition(new_e, new_j) ){
			contador++;
			q.push({new_e, new_j});
		}
	}
	return contador;
	// cout << "e: " << e << " j: " << j << " contador: " << contador << endl; 
}

int f_iquals(int e, int j){
	// cout << "e: " << e << " j: " << j << endl; 
	int contador = 0;
	for(int i = 0 ; i < 4 ; i++){
		int new_e = e + dx[i];
		int new_j = j + dy[i];
		if( isValidPosition(new_e, new_j) ){
			contador++;
			q.push({new_e, new_j});
		}
	}
	return contador;
	// cout << "e: " << e << " j: " << j << " contador: " << contador << endl; 
}

int f_diferents(int e, int j){
	// cout << "e: " << e << " j: " << j << endl; 
	int contador = 0;
	for(int i = 0 ; i < 8 ; i++){
		int new_e = e + dx[i];
		int new_j = j + dy[i];
		if( isValidPosition(new_e, new_j) ){
			contador++;
			q.push({new_e, new_j});
		}
	}
	return contador;
	// cout << "e: " << e << " j: " << j << " contador: " << contador << endl; 
}
 

void solve(){
	// cout << "any " << endl;
	odd = 0;
	even = 0;
	cin>>R>>C>>M>>N;
	Z = max(M,N);
	setDimension();
	grid.assign(R, vector<bool>(C,true));
	isVisited.assign(R, vector<bool>(C, false));
	// isVisited.assign(R, vector<bool>(C,false));

	// cout << "grid"<< endl;
	// for(int e = 0 ; e < R; e++){
	// 	for(int j = 0 ; j < C; j++){
	// 		cout << grid[e][j] << " ";
	// 	}cout << endl;
	// }cout << endl;
	// cout << "visited" << endl;
	// for(int e = 0 ; e < R; e++){
	// 	for(int j = 0 ; j < C; j++){
	// 		cout << isVisited[e][j] << " ";
	// 	}cout << endl;
	// }cout << endl;
	// return;

	int W; cin>>W;
	for(int e =0,x,y ; e < W; e++){
		cin>>x>>y;
		grid[x][y] = false;
	}
	// cout << "any 5 " << endl;
	// cout << endl;
	// for(int e = 0 ; e < R; e++){
	// 	for(int j = 0 ; j < C; j++){
	// 		cout << grid[e][j] << " ";
	// 	}cout << endl;
	// }cout << endl;
	// cout << "init q" << endl;

	q.push({0,0});
	while(!q.empty()){
		auto node = q.front(); q.pop();
		if(!isVisited[node.first][node.second]){
			isVisited[node.first][node.second] = true;
			if(M == N){
				cont = f_iquals(node.first, node.second);
				if(cont &1) odd++;
				else even++;
			}else if((M == 0) || (N == 0)){
				cont = f_zero(node.first, node.second);
				if(cont &1) odd++;
				else even++;
			}else{ // M != N
				cont = f_diferents(node.first, node.second);
				// cout << "cont: " << cont << endl;
				if(cont &1) odd++;
				else even++;
			}
			
		}
	}
	cout <<"Case " << caso++ << ": " << even << " " << odd << endl; 
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifdef DEBUG
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t; cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}