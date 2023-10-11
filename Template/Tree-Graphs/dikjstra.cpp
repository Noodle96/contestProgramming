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


const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;
vector<int> d;
vector<int> p;
void dijkstra(int s) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

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
	adj.resize(n, vector<pii>());
	int a,b,c;
	for(int e = 0 ; e < m; e++){
		cin>>a>>b>>c;
		adj[a].pb({b,c});
		adj[b].pb({a,c});
	}
	dijkstra(0);
	for(int e = 0 ; e < d.size(); e++){
		cout << d[e] << " "; 
	}cout << endl;

}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef IN_OUT
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	solve();
	return 0;
}




