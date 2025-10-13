/*
==========================================================
|  Archivo       : Genealogy.cpp
|  Autor         : Russell
|  Fecha         : 2025-10-11
|--------------------------------------------------------
|  Tópicos utilizados:
|  - rpc
|  - implementation
|  - graph
|  - dfs and similars
==========================================================
*/

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

static inline void rstrip(string &s){
    while(!s.empty() && (s.back()=='\r' || s.back()=='\n' || s.back()==' ' || s.back()=='\t')) s.pop_back();
}

void solve(){
    int n; cin >> n;
    string line; getline(cin, line);

    unordered_map<string,int> id;
    vector<vector<int>> adj;
    unordered_set<int> appears_as_child;

    auto get_id = [&](const string& s)->int{
        auto it = id.find(s);
        if(it!=id.end()) return it->second;
        int nid = (int)id.size();
        id.emplace(s, nid);
        adj.push_back({});
        return nid;
    };

    const string sep = ", son of ";
    for(int i=0;i<n;++i){
        getline(cin, line);
        rstrip(line);
        size_t p = line.find(sep);
        string A = line.substr(0, p);
        string B = line.substr(p + sep.size());
        int u = get_id(A);
        int v = get_id(B);
        appears_as_child.insert(u);
        if(u!=v){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    int m = (int)id.size();
    if(m==0){ cout << "possible\n"; return ; }

    vector<char> vis(m, 0);
    int start = 0;
    vis[start]=1;
    vector<int> st = {start};
    int seen = 0;
    while(!st.empty()){
        int x = st.back(); st.pop_back();
        ++seen;
        for(int y: adj[x]) if(!vis[y]){
            vis[y]=1; st.push_back(y);
        }
    }
    if(seen != m){ cout << "impossible\n"; return; }

    int roots = 0;
    for(int i=0;i<m;++i){
        if(!appears_as_child.count(i)) ++roots;
        if(roots > 1){ cout << "impossible\n"; return ; }
    }
    cout << "possible\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;
    //cin >> t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}