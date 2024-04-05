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
enum Color {BLACK = 0, RED = 1, WHITE = 2};
vector<vector<int>> adjList;
vector<Color> colors;
bool isBipartite;
void BFD_checkBipartite(int s){
	colors[s] = BLACK;
	queue<int> q;
	q.push(s);
	isBipartite = true;
	while(!q.empty() && isBipartite){
		int u = q.front(); q.pop();
		for(auto v : adjList[u]){
			if(colors[v] == WHITE){
				colors[v] = Color(1-colors[u]);
				q.push(v);
			}else if(colors[u] == colors[v]){
				isBipartite = false;
				break;
			}
		}
	}
}


void solve(){
	while(cin>>n){
		if(n == 0 ) break;
		adjList.assign(n, vector<int>());
		colors.assign(n, WHITE);
		cin>>m;
		for(int e = 0 ;e < m ;e++){
			cin>>u>>v;
			adjList[u].pb(v);
			adjList[v].pb(u);
		}
		BFD_checkBipartite(0);
		if(isBipartite) cout << "BICOLORABLE." << endl;
		else cout << "NOT BICOLORABLE." << endl;
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