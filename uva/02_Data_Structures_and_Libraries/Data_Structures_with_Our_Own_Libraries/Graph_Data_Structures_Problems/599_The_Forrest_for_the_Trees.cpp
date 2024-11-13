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
string line;
const int N = 26;
vector<int> adj[N];
bool isVisited[N];
int cont;
void dfs(int e){
	if(isVisited[e]) return;
	isVisited[e] = true;
	cont++;
	for(auto v: adj[e]){
		dfs(v);
	}
}
void solve(){
	vector< vector<int> > edges;
	memset(isVisited,true,sizeof(isVisited));
	while(getline(cin,line)){
		if(line[0]=='*') break;
		else{
			int u = line[1]-'A';
			int v = line[3]-'A';
			adj[u].pb(v);
			adj[v].pb(u);
		}
	}
	getline(cin,line);
	for(int e = 0 ; e< (int)line.size(); e+=2){
		isVisited[line[e]-'A'] = false;
	}
	int tree = 0,acorn = 0;
	for(int e = 0 ; e < N; e++){
		if(!isVisited[e]){
			cont = 0;
			dfs(e);
			if(cont > 1) tree++;
			else acorn++;
		}
	}
	cout << "There are " << tree <<  " tree(s) and " << acorn << " acorn(s)." << endl;
	for(int e = 0 ; e < N; e++){
		adj[e].clear();
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifdef DEBUG
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t; cin>>t;
	cin.ignore();
	while(t--){
		solve();
	}
	return 0;
}