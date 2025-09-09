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

int n,m,a,b;
int x,y,l;
int cont,allCont = 0;
vector<bool> visitado;

void DFS(int nodo_actual, int nodo_destino, int distancia_actual, int distancia_d,stack<int>& ruta_actual) {
    // Marcamos el nodo actual como visitado
    visitado[nodo_actual] = true;
    // Agregamos el nodo actual a la ruta actual
    ruta_actual.push(nodo_actual);
    // Si hemos llegado al nodo destino y la distancia actual es d
    if (nodo_actual == nodo_destino && distancia_actual == distancia_d) {
        // // Imprimimos la ruta actual
        // stack<int> ruta_temporal = ruta_actual;
        // while (!ruta_temporal.empty()) {
        //     cout << ruta_temporal.top() << " ";
        //     ruta_temporal.pop();
        // }
        // cout << endl;
		cont++;
    }

    // Exploramos todos los vecinos del nodo actual
    for (auto& vecino : adj[nodo_actual]) {

        if (!visitado[vecino.first] && distancia_actual + vecino.second <= distancia_d) {
            // Llamamos recursivamente al DFS con el vecino como nodo actual y la distancia actualizada
            DFS(vecino.first, nodo_destino, distancia_actual + vecino.second, distancia_d, ruta_actual);
        }
    }

    // Desmarcamos el nodo actual como visitado y lo eliminamos de la ruta actual
    visitado[nodo_actual] = false;
    ruta_actual.pop();
}

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
	cin>>n>>m>>a>>b;
	a--,b--;
	adj.assign(n,vector<pair<int,ll>>());
	visitado.assign(n,false);
	for(int e = 0 ; e < m; e++){
		cin>>x>>y>>l;
		allCont+=l;
		x--,y--;
		adj[x].pb({y,l});
		adj[y].pb({x,l});
	}
	dijkstra(a);
	//show distance
	// for(int e = 0 ; e<  (int)d.size();e++){
	// 	cout << d[e] << " ";
	// }cout << endl;
	
	ll shortesPathLen = d[b];


	stack<int> ruta_actual;
	cont = 0;
	DFS(a, b, 0, shortesPathLen,ruta_actual);
	// cout << "cont: " << cont << endl;
	cout << allCont -cont*shortesPathLen << endl;


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