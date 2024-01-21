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
vector<bool> visited;
vector< vector<int> > adjList;
void dfs(int u){
	visited[u] = true;
	for(auto e: adjList[u]){
		if(!visited[e]) dfs(e);
	}
}

void solve(){
	char ch; cin>>ch;
	int N = ch-'@';

	// cout << "N: " << N << endl;

	//clean for each case
	
	adjList.assign(N, vector<int>());
	visited.assign(N, false);

	string line;
	cin.ignore();
	while(getline(cin, line) && line != ""){
		int a,b;
		a = line[0]-'@';
		b = line[1]-'@';
		a--;b--;
		// cout << "a: " << a << " b: " << b << endl;
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}
	int subgraph = 0;
	for(int u = 0 ;u < N ; u++){
		if(!visited[u]){
			dfs(u);
			subgraph++;
		}
	}
	// cout << "subgraph: "<< subgraph << endl;
	cout << subgraph << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifdef DEBUG
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t; cin>>t;
	int t_ = t;
	while(t--){
		solve();
		if((t_--)>1) cout << endl;
	}
	
	return 0;
}