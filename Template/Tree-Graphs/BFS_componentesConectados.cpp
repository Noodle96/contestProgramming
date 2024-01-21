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
vector<vector<int>> graph;
vector<bool> visited;
void bfs(int start) {
	int n = graph.size();
	queue<int> q;

	visited[start] = true;
	q.push(start);

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		// cout << node << " ";

		for (int neighbor : graph[node]) {
			if (!visited[neighbor]) {
				visited[neighbor] = true;
				q.push(neighbor);
			}
		}
	}
}
void solve(){
	int n, m;
	cin >> n >> m;
	graph.assign(n, vector<int>());
	visited.assign(n, false);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		u--; v--;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int components = 0;
	for(int e = 0 ; e < n; e++){
		if(!visited[e]){
			bfs(e);
			components++;
		}
	}
	cout << components << endl;

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