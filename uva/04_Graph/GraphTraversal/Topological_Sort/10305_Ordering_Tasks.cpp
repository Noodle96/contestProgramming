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
vector< vector<int> > adj;
vector<bool> isVisited;
vector<int> topologicalSort;

void dfs(int e){
	if(isVisited[e])return;
	isVisited[e] = true;
	for(auto u: adj[e]){
		if(!isVisited[u]) dfs(u);
	}
	topologicalSort.pb(e);
}

void solve(){
	while(cin>>n>>m){
		if(n == 0 && m == 0) break;
		topologicalSort.clear();
		adj.assign(n,vector<int>());
		isVisited.assign(n,false);
		for(int e = 0 ; e < m; e++){
			int a,b;
			cin>>a>>b;
			a--,b--;
			adj[a].pb(b);
		}
		for(int e = 0 ; e < n; e++){
			if(!isVisited[e]) dfs(e);
		}
		reverse(all(topologicalSort));
		for(auto e: topologicalSort){
			cout << e+1 << " ";
		}cout << endl;
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