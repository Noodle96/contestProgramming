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

const int INF = 1e9;

int bellmanFord(int s, vector<vector<pii>> &g){
    int n = g.size();
    vector<int> d(n,INF);
    d[s] = 0;
    for(int i = 0; i < n; i++){
        for(int u = 0; u < n; u++){
            for(auto edge: g[u]){
                int v = edge.first;
                int w = edge.second;
                if(d[u] + w < d[v]){
                    // Si esta es la "n" relajacion, entonces hay un ciclo negativo
                    if(i == n-1){
                        return -1;
                    }
                    d[v] = d[u] + w;
                }
            }
        }
    }
    return 1;
}

void solve(){
    int N; cin>>N;
    while(N--){
        int n,m; cin>>n>>m;
        vector<vector<pii>> g(n, vector<pii>());
        int a,b,c;
        for(int e = 0 ; e < m ; e++){
            cin>>a>>b>>c;
            g[a].pb({b,c});
        }
        int ans = bellmanFord(0,g);
        cout << (ans == -1 ? "possible" : "not possible") << endl;
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