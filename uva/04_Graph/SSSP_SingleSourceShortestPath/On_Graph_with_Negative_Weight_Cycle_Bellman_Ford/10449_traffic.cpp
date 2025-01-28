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
using pil = pair<int, ll>;
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

int casoP = 1;
const ll INF = 1e18;

int bellmanFord(int source, vector<vector<pil>> &g, vector<ll> &d){
    int n = g.size();
    d[source] = 0;
    // n-1 relajaciones
    for(int e = 0 ; e < n-1; e++){
        for(int u = 0; u < n;u++){
            for(auto edge: g[u]){
                int v = edge.first;
                ll w = edge.second;
                if(d[u] != INF && d[u] + w < d[v]){
                    d[v] = d[u] + w;
                }
            }
        }
    }

    // cout << "d before: " << endl;
    //     for(auto d_i: d){
    //         cout << d_i << " ";
    //     }cout << endl;

    // verificacion si es que existe un ciclo
    int ans = 1;
    for(int e = 0;  e< 2;e++){
        for(int u = 0; u < n;u++){
            for(auto edge: g[u]){
                int v = edge.first;
                ll w = edge.second;
                if(d[u] != INF && d[u] + w < d[v]){
                    d[v] = -INF;
                    ans = -1;
                }
            }
        }
    }
    // cout << "d after: " << endl;
    //     for(auto d_i: d){
    //         cout << d_i << " ";
    //     }cout << endl;
    return ans;
}

void solve(){
    int n;
    while(cin>>n){
        // cout << "n: " << n << endl;
        vector<ll> busyness(n);
        vector<vector<pil>> g(n, vector<pil>());
        for(int e = 0 ; e < n; e++){
            cin>>busyness[e];
        }
        int m; cin>>m;
        // cout << "m: " << m << endl;
        int a,b;
        for(int e = 0 ; e < m; e++){
            cin>>a>>b;
            a--; b--;
            ll total = (busyness[b]-busyness[a])*(busyness[b]-busyness[a])*(busyness[b]-busyness[a]);
            g[a].pb({b, total});
        }
        // cout << "print graph" << endl;
        // for(int e = 0 ; e < n;  e++){
        //     cout << "Nodo " << e+1 << ": " << endl;
        //     for(auto edge: g[e]){
        //         cout << "\t(" << edge.first+1 << " " << edge.second << ") ";
        //     }cout << endl;
        // }
        vector<ll> d(n, INF);
        if(n > 0) int ans = bellmanFord(0, g, d);
        int q; cin>>q;
        // cout << "q: " << q << endl;
        int destination;
        cout << "Set #" << casoP++ << endl;
        while(q--){
            cin>>destination;
            destination--;
            if(d[destination] < 3 || d[destination] == INF) cout << "?" << endl;
            else cout << d[destination] << endl;
        }
        
    }
}
void solve2(){
    int a = 4;
    cout << (a^3) << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    solve();
    // solve2();
    return 0;
}