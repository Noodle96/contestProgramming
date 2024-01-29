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
int n,m;
vector<vector<int>> graph;
vector<bool> isVisited;
int hojas;
int X,Y;
bool isLeaf(int x){
	return graph[x].size()==1;
}

void dfs(int x){
	if(isVisited[x]) return;
	isVisited[x] = true;
	if(isLeaf(x)) hojas++;
	for(auto e: graph[x]){
		dfs(e);
	}
}

void solve(){
	cin>>n>>m;
	graph.assign(n,vector<int>());
	isVisited.assign(n,false);
	for(int e = 0 ; e < m ; e++){
		int a,b; cin>>a>>b;
		a--;b--;
		graph[a].pb(b);
		graph[b].pb(a);
	}
	// print graph
	// for(int e = 0 ; e < n ; e++){
	// 	cout << e << ": ";
	// 	for(auto e2:graph[e]) cout << e2 << " ";
	// 	cout << endl;
	// }
	// cout << "dfs: " << endl;
	//DE CUALQUIER NODO QUE ELIGA NOS DARA EL NUMERO DE HOJAS TOTALES.
	hojas = 0;
	dfs(0); // calculamos el numero de hojas
	n--;
	X= n-hojas;
	Y = hojas/X;
	cout << X << " " << Y << endl;
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