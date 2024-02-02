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

const int N = 20;
char grid[N][N];
bool isVisited[N][N];
int r,c;
int a,b;
char l,w;
int numRegiones;
int idx[] = {0,-1,0,1};
int idy[]= {1,0,-1,0};

bool isValidPosition(int x, int y){
	return x >= 0 && x < r ;
}

void dfs(int x, int y){
	if(isVisited[x][y]) return;
	numRegiones++;
	isVisited[x][y] = true;
	for(int e = 0 ; e < 4; e++){
		int new_x = x + idx[e];
		int new_y = y  + idy[e];
		if(new_y == c) new_y = 0;
		if(new_y == -1) new_y = c-1;
		if(isValidPosition(new_x,new_y)  && grid[new_x][new_y] == l){
			dfs(new_x,new_y);
		}
	}

}
void solve(){
	while(cin>>r>>c){
		// cout << "r: " <<r << " c: " << c << endl;
		map<char, int> mapa;
		// cout << "r: " << r << "c: " << c << endl;
		for(int e = 0 ; e < r; e++){
			for(int f = 0; f < c; f++){
				cin>>grid[e][f];
				mapa[grid[e][f]]++;
				isVisited[e][f] = false;
			}
		}
		// print map
		// cout << "mapa: " << endl;
		// for(auto e: mapa){
		// 	cout << e.first << " " << e.second << endl;
		// }cout << endl;

		// //print the grid
		// for(int e = 0 ; e < r; e++){
		// 	for(int f = 0; f < c; f++){
		// 		cout << grid[e][f];
		// 	}
		// 	cout << endl;
		// }cout << endl;
		cin>>a>>b;
		l = grid[a][b];
		w;
		for(auto e: mapa){
			if(e.first != l){
				w = e.first;
				break;
			}
		}
		// cout << "l: " << l << " w: " << w << endl;

		//PRIMERO HACEMOS UN DFS PARA DESCARTAR EL CONTINENTE DEL COMANDANTE
		dfs(a,b);

		set<int> ans;
		for(int e = 0 ;e < r ; e++){
			for(int j = 0; j < c; j++){
				if(!isVisited[e][j] && grid[e][j] == l){
					numRegiones = 0;
					dfs(e,j);
					// cout << "numRegiones: " << numRegiones << endl;
					ans.insert(numRegiones);
				}
			}
		}
		// print ans
		// cout << "ans: " << endl;
		// for(auto e: ans){
		// 	cout << e << endl;
		// }cout << endl;
		if(ans.size() == 0){cout << 0 << endl;}
		else{
			cout << *ans.rbegin() << endl;
			// cout << *max_element(all(ans)) << endl;
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