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
using pil = pair<int,ll>;

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


const ll INF = 1e18;

vector<ll> dijkstra_minimo(int s, vector<vector<pair<int,ll>>> &graph ){
    // 1.- Assign
    int n = graph.size();
    // cout << "n: " << n << endl;
    vector<ll> d(n, INF);
    d[s] = 0;

    // 2.- Create pq
    priority_queue<pli,vector<pli>,greater<pli>> q;
    q.push({0LL,s});
    while(!q.empty()){
        // 3.- GetMin and Delete
        int v = q.top().second;
        ll d_v = q.top().first;
        q.pop();

        // 4.- Verify
        if(d_v != d[v]) continue;

        // 5.- Add adyacencias to pq
        for(auto edge: graph[v]){
            int to = edge.first;
            ll len = edge.second;

            if(d[v] + len < d[to]){
                d[to] = d[v] + len;
                q.push({d[to], to});
            }
        }
    }
    return d;
}

vector<ll> dijkstra_maximo(int s, vector<vector<pair<int,ll>>> &graph ){
    // 1.- Assign
    int n = graph.size();
    // cout << "n: " << n << endl;
    vector<ll> d(n, -INF);
    d[s] = 0;

    // 2.- Create pq
    priority_queue<pli> q;
    q.push({0LL,s});
    while(!q.empty()){
        // 3.- GetMin and Delete
        int v = q.top().second;
        ll d_v = q.top().first;
        q.pop();

        // 4.- Verify
        if(d_v < d[v]) continue;

        // 5.- Add adyacencias to pq
        for(auto edge: graph[v]){
            int to = edge.first;
            ll len = edge.second;

            if(d[v] + len > d[to]){
                d[to] = d[v] + len;
                q.push({d[to], to});
            }
        }
    }
    return d;
}
// void findAllPaths(int current, int start, vector<int> &path, vector<vector<int>> &allPath){
//     if(current == start){
//         path.pb(current);
//         allPath.push_back(vector<int>(path.rbegin(), path.rend()));
//         path.pop_back();
//         return;
//     }
//     path.pb(current);
//     for(auto nodo: previous[current]){
//         findAllPaths(nodo, start, path, allPath);
//     }
//     path.pop_back();
// }
void solve(){
    int C; cin>>C;
    while(C--){
        int n,m,s,t;
        ll p;
        cin>>n>>m>>s>>t>>p;
        s--; t--;
        vector<vector<pair<int, ll>>> adj(n, vector<pair<int,ll>>());
        vector<vector<pair<int, ll>>> adj_reverse(n, vector<pair<int,ll>>());
        queue<tuple<int, int, ll>> edges;
        int a,b;
        ll c;
        for(int e = 0 ; e < m; e++){
            cin>>a>>b>>c;
            a--,b--;
            adj[a].pb({b,c});
            adj_reverse[b].pb({a,c});
            edges.push(make_tuple(a,b,c));
        }
        // cout << "before dijkstra" << endl;
        vector<ll> fromS = dijkstra_minimo(s,adj);
        // cout << "S: " << fromS.size() << endl;
        vector<ll> fromT= dijkstra_minimo(t,adj_reverse);
        // cout << "T: " << fromT.size() << endl;
        ll ans = -1;
        int x,y; ll w;
        while(!edges.empty()){
            tie(x,y,w) = edges.front(); edges.pop();
            ll totalCost = fromS[x] + w + fromT[y];
            // cout << "totalCost: " << totalCost << endl; 
            if(totalCost <= p){
                ans = max(ans,w);
            }
        }
        cout << ans << endl;
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