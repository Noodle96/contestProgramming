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


//Remember that adj:  [int] =>[int, ll] 
const ll INF = 1e18;
vector<vector<pair<int, ll>>> adj;
vector<ll> d;
vector<int> p;
void dijkstra(int s) {
	//1.- asign
	int n = adj.size();
	d.assign(n, INF);
	p.assign(n, -1);
	d[s] = 0;

	//2.- create a priorityQueue
	priority_queue<pli, vector<pli>, greater<pli>> q;
	q.push({0, s});
	while (!q.empty()) {
		//3.- getMin and deleteMin
		int v = q.top().second;
		ll d_v = q.top().first;
		q.pop();

		//4.- verify
		if (d_v != d[v]) continue;

		// 5.- add adyacencias to priorityQueue
		for (auto edge : adj[v]) {
			int to = edge.first;
			ll len = edge.second;

			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				p[to] = v;
				q.push({d[to], to});
			}
		}
	}
}
void solve(){
	int n,m; cin>>n>>m;
	int a,b;
	ll c;
	adj.assign(n, vector<pair<int,ll>>());
	for(int e = 0 ; e < m; e++){
		cin>>a>>b>>c;
		a--,b--;
		adj[a].pb({b,c});
		adj[b].pb({a,c});
	}
	dijkstra(0);
	// for(int e = 0 ; e < n; e++){
	// 	cout << d[e] << " ";
	// }cout << endl;
	// for(int e = 0 ; e < n; e++){
	// 	cout << p[e] << " ";
	// }cout << endl;

	int objetivo = p[n-1];
	if(objetivo == -1){cout << -1 << endl; return;}
	vector<int> ans;
	// cout << n << " ";
	ans.pb(n);
	while(objetivo != 0){
		ans.pb(objetivo+1);
		// cout << objetivo +1 << " ";
		objetivo = p[objetivo];
	}
	ans.pb(1);
	// cout << 1 << endl;
	reverse(all(ans));
	for(int e = 0 ; e < ans.size(); e++){
		cout << ans[e] << " ";
	}cout << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	// #ifndef IN_OUT
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
	
	solve();
	return 0;
}