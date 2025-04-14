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

vector<vector<int>> adj;
vector<bool> isVisited;
int total;
// count the nodes

void dfs(int v){
    if(isVisited[v]) return;
    isVisited[v] = true;
    total++;
    for(int u : adj[v]){
        dfs(u);
    }
}

void solve(){
    int n;
    cin>>n;
    vector<int> vec(n);
    adj.assign(n,vector<int>());
    isVisited.assign(n,false);
    for(int e = 0 ;e < n ; e++){
        cin>>vec[e];
    }
    for(int e = 0 ;e < n ; e++){
        int u = vec[e];
        adj[e].pb(u-1);
    }
    total = 0;
    dfs(0);
    cout << total << endl;

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