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
enum Color {BLACK = 0, RED = 1, WHITE = 2};
int n,m,u,v;
vector< vector<int> > adjList;
vector<Color> color;
bool isBipartite;
void BFS(int u){
	color[u] = BLACK;
	queue<int> q;
	q.push(u);
	isBipartite = true;
	while(!q.empty() && isBipartite){
		int u = q.front(); q.pop();
		for(auto &v: adjList[u]){
			if(color[v] == WHITE){
				color[v] = Color(1-color[u]);
				q.push(v);
			}else if(color[u] == color[v]){
				isBipartite = false;
				break;
			}
		}
	}
}

void solve(){
	cin>>n>>m;
	adjList.assign(n, vector<int>());
	color.assign(n,WHITE);
	for(int e = 0 ; e < m; e++){
		cin>>u>>v;
		adjList[u].pb(v);
		adjList[v].pb(u);
	}
	BFS(0);
	if(isBipartite) cout << "Is Bipartite" << endl;
	else cout << "Isnt Bipartite" << endl;
	cout << "colors" << endl;
	for(int e = 0 ; e < n; e++){
		cout << color[e] << endl;
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