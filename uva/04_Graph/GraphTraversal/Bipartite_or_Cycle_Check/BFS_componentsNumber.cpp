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

vector< vector<int> > adjList;
vector<bool> isVisited;
int n,m,u,v;
int numComponents;

void BFS(int u){
	isVisited[u] = true;
	queue<int> q;
	q.push(u);
	while(!q.empty()){
		auto u = q.front(); q.pop();
		for(auto v: adjList[u] ){
			if( isVisited[v] ) continue;
			isVisited[v]= true;
			q.push(v);
		}
	}
}
void solve(){
	cin>>n>>m;
	adjList.assign(n, vector<int>());
	isVisited.assign(n, false);
	for(int e = 0 ; e < m; e++){
		cin>>u>>v;
		adjList[u].pb(v);
		adjList[v].pb(u);
	}
	numComponents = 0;
	for(int e = 0 ; e < n; e++){
		if(!isVisited[e]){
			BFS(e);
			numComponents++;
		}
	}
	cout << "Numero de componentes: " << numComponents << endl;
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