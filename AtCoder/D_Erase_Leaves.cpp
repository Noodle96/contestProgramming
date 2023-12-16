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

vector<vector<int>> adjList;
vector<bool> isVisited;
int cont;
// int globalCont = INT_MAX;
vector<int> ans;

void dfs(int u){
	if(isVisited[u]) return;
	isVisited[u] = true;
	cont++;
	for(auto e: adjList[u]){
		if(!isVisited[e]) dfs(e);
	}
}

void f(int u)	{
	//if(isVisited[u]) return;
	isVisited[u] = true;
	for(auto e: adjList[u]){
		cont = 0;
		dfs(e);
		// cout <<"cont: " << cont << endl;
		ans.pb(cont);
		// globalCont = min(globalCont,cont);
		
	}
}

void solve(){
	int n; cin>>n;
	adjList.assign(n, vector<int>());
	isVisited.assign(n, false);
	for(int e = 0,a,b ; e < n-1; e++){
		cin>>a>>b;
		a--,b--;
		adjList[a].pb(b);
		adjList[b].pb(a);
	}
	// 1 is leaf
	if(adjList[0].size()== 1){cout << 1 << endl;}
	else{
		f(0);
		// cout << globalCont + 1 << endl;
		sort(all(ans));
		int global = 0;
		for(int e = 0 ; e < ans.size()-1; e++){
			global += ans[e];
		}
		cout << global +1 << endl;
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