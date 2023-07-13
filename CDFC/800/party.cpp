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

const int N = 2000;
vector<int> adj[N];
vector<int> visited(N,0);
int maxGroups = 0;
vector<int> roots;

void dfs(int v, int length = 1){
	if(visited[v]) return;
	// msg("v: ",v);
	// maxLength = max(maxLength, length);
	maxGroups = max(maxGroups,length);
	visited[v] = 1;
	for(int e = 0 ; e < adj[v].size(); e++){
		dfs(adj[v][e], length+1);
	}
}

void solve(){
	int n; cin>>n;
	for(int e = 0,u ; e < n; e++){
		cin>>u;
		if(u != -1){
			u--;
			//adj[e].pb(u);
			adj[u].pb(e);
		}else{
			roots.pb(e);
		}
	}
	for(int e = 0 ;e < roots.size() ; e++){
		dfs(roots[e]);
	}
	// for(int e = 0 ;e < n ; e++){
	// 	dfs(e, maxGroups);
	// }
	cout << maxGroups << endl;
}
int main(){
	// #ifndef IN_OUT
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif	
	solve();
	return 0;
}