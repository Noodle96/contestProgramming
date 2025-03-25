#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
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
using vll = vector<ll>;

#define pb push_back
#define mp make_pair

const ll INF = 1e18;

ll gcd(ll a,ll b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const uint MOD = 1000000007;
template<uint mod = MOD> struct mint { // 1000000007  1000000009
	uint x;
	mint() : x(0) {}
	mint(ll _x) {
		_x %= mod;
		if (_x < 0) _x += mod;
		x = _x;
	}
 
	mint& operator += (const mint &a) {
		x += a.x;
		if (x >= mod) x -= mod;
		return *this;
	}
	mint& operator -= (const mint &a) {
		x += mod - a.x;
		if (x >= mod) x -= mod;
		return *this;
	}
	mint& operator *= (const mint &a) {
		x = (ull)x * a.x % mod;
		return *this;
	}
	mint pow(ll pw) const {
		mint res = 1;
		mint cur = *this;
		while(pw) {
			if (pw & 1) res *= cur;
			cur *= cur;
			pw >>= 1;
		}
		return res;
	}
	mint inv() const {
		assert(x != 0);
		uint t = x;
		uint res = 1;
		while(t != 1) {
			uint z = mod / t;
			res = (ull)res * (mod - z) % mod;
			t = mod - t * z;
		}
		return res;
	}
	mint& operator /= (const mint &a) {
		return *this *= a.inv();
	}
	mint operator + (const mint &a) const {
		return mint(*this) += a;
	}
	mint operator - (const mint &a) const {
		return mint(*this) -= a;
	}
	mint operator * (const mint &a) const {
		return mint(*this) *= a;
	}
	mint operator / (const mint &a) const {
		return mint(*this) /= a;
	}
 
	bool operator == (const mint &a) const {
		return x == a.x;
	}
	bool operator != (const mint &a) const {
		return x != a.x;
	}
	bool operator < (const mint &a) const {
		return x < a.x;
	}
};

enum Status{UNVISITED = -1, VISITED = 1};
vector<vector<int>> adj;
vector<vector<int>> adj_transpose;
vector<Status> status;
vector<int> TopologicalSort;
vector<int> temporalComponents;
vector<vector<int>> sccs;
vector<int> scc_id;
vector<int> costos;

using Mint = mint<>;

void Kosaraju(int u, int model){
    if(model == 2) temporalComponents.pb(u);
    status[u] = VISITED;
    vector<int> &neighbours = (model == 1) ? adj[u] : adj_transpose[u];
    for(auto v: neighbours){
        if(status[v] == UNVISITED){
            Kosaraju(v,model);
        }
    }
    if(model == 1) TopologicalSort.pb(u);
}

void solve(){
    int n; cin>>n;
    costos.assign(n,0);
    for(int i = 0 ; i < n; i++) cin>>costos[i];
    adj.assign(n, vector<int>());
    adj_transpose.assign(n,vector<int>());
    scc_id.assign(n,-1);

    int m; cin>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        u--;v--;
        adj[u].pb(v);
        adj_transpose[v].pb(u);
    }

    // Paso 1: Encontrar SCCs con Kosaraju
    TopologicalSort.clear();
    status.assign(n,UNVISITED);
    for(int e = 0 ;e < n ; e++){
        if(status[e] == UNVISITED){
            Kosaraju(e,1);
        }
    }
    status.assign(n,UNVISITED);
    sccs.clear();
    int scc_count = 0;
    for(int u = n-1; u >= 0; u--){
        if(status[TopologicalSort[u]] == UNVISITED){
            temporalComponents.clear();
            Kosaraju(TopologicalSort[u],2);
            for(auto v: temporalComponents) scc_id[v] = scc_count;
            scc_count++;
            sccs.pb(temporalComponents);
        }
    }

    // Contar cual es el minimo costo de cada componente
    ll min_cost = 0;
    Mint ways(1);
    for(auto scc: sccs){
        ll min_cost_scc = INF;
        for(auto v: scc){
            if(costos[v] < min_cost_scc) min_cost_scc = costos[v];
        }
        min_cost += min_cost_scc;
        int totalMinimum = 0;
        for(auto v: scc){
            if(costos[v] == min_cost_scc) totalMinimum++;
        }
        ways *= Mint(totalMinimum);
    }
    cout << min_cost << " " << ways.x << endl;
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