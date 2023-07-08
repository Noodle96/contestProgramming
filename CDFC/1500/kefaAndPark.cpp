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
#define fi first
#define se second

const int N = 1e5+7;
vector<int> adj[N];
vector<bool> isVisited(N,0);
int hasCat[N];
int n,m,u,v;
vector<int> hojas;
int visitRestaurant = 0;


void printAdj(){
	for(int e = 0 ; e < n; e++){
		cout << e << ": ";
		for(auto it = adj[e].begin() ; it != adj[e].end(); it++){
			cout << *it <<" ";
		}cout << endl;
	}
}

bool isLeaf(int node){
	if (node != 0 && adj[node].size() == 1) return true;
	return false;
}

void dfs(int v, int hascat_ ){
	if(isVisited[v]) return;
	// msg("hascat_ > m: ",(hascat_ > m));
	if(hascat_ > m) return; // ya no entra a sus hijos
	// msg("v: ", v);
	isVisited[v] = true;
	if(isLeaf(v)){
		// msg("isleaf: ",v);
		visitRestaurant++;
		return;
	}
	// if(adj[v].size() == 0) hojas.pb(v);
	for(int e = 0 ; e < adj[v].size(); e++){
		if( hasCat[ adj[v][e] ] == 1 && hascat_ > 0){
			dfs(adj[v][e], hasCat[ adj[v][e] ] + hascat_  );
		}else{
			dfs(adj[v][e], hasCat[ adj[v][e] ]);
		}
		
	}
}

void printHojas(){
	for(auto it = hojas.begin(); it != hojas.end() ; it++){
		cout << *it << " ";
	}cout <<endl;
}
void solve(){
	cin>>n>>m;
	for(auto e = 0 ; e < n; e++)cin>>hasCat[e];
	for(int e = 0 ; e< n-1; e++){
		cin>>u>>v;
		u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	// printAdj();
	// msg("dfs","");
	dfs(0, hasCat[0]);
	msg(visitRestaurant,"");
	// msg("canti_Res: ", visitRestaurant);
	// msg("hojas","");
	// printHojas();
}

int main(){
	// #ifndef IN_OUT
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
	solve();
	return 0;
}