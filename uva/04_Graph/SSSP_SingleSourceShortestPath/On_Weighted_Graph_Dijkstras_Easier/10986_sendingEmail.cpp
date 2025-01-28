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

vector<vector<pii>>adj;
vector<int> d;
vector<int> p;
const int INF = 1e9;
int caso = 1;

void dijkstra(int s) {
	//1.- asign
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);
    d[s] = 0;

	//2.- create a priorityQueue
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});

    while (!q.empty()) {
		//3.- getMin and deleteMin
        int v = q.top().second;
        int d_v = q.top().first;
		// cout << "v: " << v << " d_v " << d_v<< endl;
        q.pop();

		//4.- verify
        if (d_v != d[v]){
			// cout << "continue in: " << "v: " << v << " d_v " << d_v<< endl;
			continue;
		}

		// 5.- add adyacencias to priorityQueue
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
    int casos; cin>>casos;
    while(casos--){
        int n,m,s,t;
        cin>>n>>m>>s>>t;
        int a,b,c;
        p.clear();
        d.clear();
        adj.assign(n, vector<pii>());
        for(int e = 0 ; e < m; e++){
            cin>>a>>b>>c;
            adj[a].pb({b,c});
            adj[b].pb({a,c});
        }
        dijkstra(s);
        if(d[t] != INF){
            cout << "Case #"<< caso++ << ": " << d[t] << endl;
        }else{
            cout << "Case #"<< caso++ << ": unreachable" << endl;
        }
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