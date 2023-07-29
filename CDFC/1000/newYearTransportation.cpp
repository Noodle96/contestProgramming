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

const int N = 3e4+1;
vector<int> adj[N];
int t;
bool ans = false;

void dfs(int v){
	if(v == t){
		ans = true;
		return;
	}
	for(auto &v: adj[v]){
		dfs(v);
	}
}

void solve(){
	int n; cin>>n>>t;
	vector<int> portal(n-1);
	for(int e = 0 ,temp; e < n-1; e++){
		cin>> temp;
		portal[e+1] = temp;

		adj[e+1].pb(e+1+portal[e+1]);
	}
	// for(int e = 0 ; e < n; e++){
	// 	cout << e << ": ";
	// 	for(auto it = adj[e].begin() ;it != adj[e].end() ; it++){
	// 		cout << *it << " ";
	// 	}cout << endl;
	// }
	dfs(1);
	cout << ( ans?"YES":"NO" ) << endl;

}
int main(){
	solve();
	return 0;
}