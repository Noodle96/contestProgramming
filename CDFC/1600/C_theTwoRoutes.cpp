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

const int N = 404;
int routes[N][N];
vector<vector<pii>>adjRailway,adjRoad;

vector<int> dRailway;
vector<int> dRoad;
const int INF = 1e9;
void dijkstra01(int s){
	//01
	int n = adjRailway.size();
	dRailway.assign(n,INF);
	dRailway[s] = 0;

	//02
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({0,s});
	while(!q.empty()){
		//03
		int v = q.top().second;
		int d_v = q.top().first;
		q.pop();

		//04
		if(dRailway[v] != d_v) continue;
		for(auto edge: adjRailway[v]){
			//05
			int to = edge.first;
			int len = edge.second;
			if(dRailway[v]+len < dRailway[to]){
				dRailway[to] = dRailway[v]+len;
				q.push({dRailway[to], to}); 
			}
		}
	}
}

void dijkstra02(int s){
	//01
	int n = adjRoad.size();
	dRoad.assign(n,INF);
	dRoad[s] = 0;

	//02
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({0,s});
	while(!q.empty()){
		//03
		int v = q.top().second;
		int d_v = q.top().first;
		q.pop();

		//04
		if(dRoad[v] != d_v) continue;
		for(auto edge: adjRoad[v]){
			//05
			int to = edge.first;
			int len = edge.second;
			if(dRoad[v]+len < dRoad[to]){
				dRoad[to] = dRoad[v]+len;
				q.push({dRoad[to], to}); 
			}
		}
	}
}


void solve(){
	int n,m; cin>>n>>m;
	int a,b;
	for(int e = 0 ;e < m ; e++){
		cin>>a>>b;
		a--,b--;
		routes[a][b] = 1;
		routes[b][a] = 1;
	}
	if(m == n*(n-1)){
		cout << -1 << endl;
		return;
	}
	adjRailway.assign(n, vector<pii>());
	adjRoad.assign(n, vector<pii>());
	for(int e = 0 ;e < n ; e++){
		for(int j = 0 ; j < n; j++){
			if(e!=j){
				if(routes[e][j] == 1 ){ // is railways
					adjRailway[e].pb({j,1});
				}else{
				// is road
					adjRoad[e].pb({j,1});
				}
			}
		}
	}
	dijkstra01(0);
	dijkstra02(0);
	// for(int e = 0 ;e < dRailway.size() ; e++){
	// 	cout << dRailway[e] << " ";
	// }cout <<endl;
	// for(int e = 0 ;e < dRoad.size() ; e++){
	// 	cout << dRoad[e] << " ";
	// }cout <<endl;
	if(dRailway[n-1] != INF && dRoad[n-1] != INF){
		cout << max(dRailway[n-1],dRoad[n-1]) << endl;
	}else{
		cout << -1 << endl;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	// for(int e = 0 ; e < N; e++){
	// 	for(int j =0 ; j <N; j++){
	// 		cout << routes[e][j]<< " ";
	// 	}cout << endl;
	// }cout << endl;
	// #ifndef IN_OUT
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
	
	solve();
	return 0;
}