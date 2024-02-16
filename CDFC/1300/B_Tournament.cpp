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
vector< vector<int> > graph;
vector<bool> isVisited;
int n;
int a,b;
bool flag;
void dfs(int inicio, int objetivo){
	if(isVisited[inicio]) return;
	isVisited[inicio] = true;
	if(inicio == objetivo) flag = true;
	for(auto e: graph[inicio]){
		dfs(e,objetivo);
	}
}

void solve(){
	cin>>n;
	graph.assign(n+1,vector<int>());
	isVisited.assign(n+1,false);
	map<int,int> map;
	for(int e = 0 ; e < (n*(n-1)/2)-1; e++){
		cin>>a>>b;
		graph[a].pb(b);
		map[a]++;
		map[b]++;
	}
	vector<int> faltantes;
	for(auto e: map){
		if(e.second != n-1)faltantes.pb(e.first);
	}
	// for(auto e: faltantes){
	// 	cout << e << " ";
	// }cout << endl;
	flag = false;
	// ver si existe un camino entre falta[0] -> ..... -> falta[1]
	dfs(faltantes[0], faltantes[1]);
	if(flag){
		cout << faltantes[0] << " " << faltantes[1] << endl;
	}else{
		cout << faltantes[1] << " " << faltantes[0] << endl;
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