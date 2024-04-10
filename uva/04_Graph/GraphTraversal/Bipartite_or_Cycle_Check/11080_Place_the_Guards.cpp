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

int n,m,u,v;
enum Color{BLACK = 0, RED = 1, WHITE = 2};
vector<vector<int> > adjList;
vector<Color> color;
bool isBipartite;
vector<bool> isVisited;
int black,red;

void bipartiteCheck(int s){
	color[s] = BLACK;
	queue<int> q;
	q.push(s);
	isBipartite = true;
	while(!q.empty() && isBipartite){
		int u = q.front(); q.pop();
		for(auto v: adjList[u]){
			if(color[v] == WHITE){
				color[v] = Color(1 - color[u]);
				q.push(v);
			}else if(color[v] == color[u]){
				isBipartite = false;
				break;
			}
		}
	}
}

void dfs(int x){
	if(isVisited[x]) return;
	isVisited[x] = true;
	if(color[x] == BLACK) black++;
	else red++;
	for(auto v: adjList[x]){
		if(!isVisited[v]) dfs(v);
	}
}

void solve(){
	cin>>n>>m;
	adjList.assign(n,vector<int>());
	color.assign(n,WHITE);
	isVisited.assign(n,false);
	for(int e = 0 ; e < m; e++){
		cin>>u>>v;
		adjList[u].pb(v);
		adjList[v].pb(u);
	}
	for(int e = 0 ; e < n; e++){
		if(color[e] == WHITE){
			bipartiteCheck(e);
			if(!isBipartite){
				cout << -1 << endl;
				return;
			}
		}
	}
	if(isBipartite){
		int ans = 0;
		for(int e = 0; e < n; e++){
			if(!isVisited[e]){
				black = 0, red = 0;
				dfs(e);
				// cout << "black: " << black << " red: " << red << endl;
				if(black == 0 || red == 0){
					ans += max(black,red);
				}else{
					ans += min(black,red);
				}
				
			}
		}
		cout << ans << endl;
	}else cout << -1 << endl;
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