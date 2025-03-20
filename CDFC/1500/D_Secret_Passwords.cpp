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
vector<bool> visited;
vector<bool> active;
int numComponents = 0;

void dfs(int e){
    if(visited[e]) return;
    visited[e] = true;
    for(auto v : adj[e]){
        dfs(v);
    }
}

void solve(){
    int n;
    cin>>n;
    vector<string> data(n);
    for(int e = 0 ; e < n; e++) cin>>data[e];

    adj.assign(26,vector<int>());
    visited.assign(26,false);
    active.assign(26,false);

    for(int e = 0 ; e < n; e++){
        for(int j = 0 ; j < data[e].size(); j++){
            active[data[e][j]-'a'] = true;
            for(int k = j+1; k < data[e].size(); k++){
                if(data[e][j] != data[e][k]){
                    adj[data[e][j]-'a'].pb(data[e][k]-'a');
                    adj[data[e][k]-'a'].pb(data[e][j]-'a');
                }
            }
        }
    }
    for(int e = 0 ; e < 26; e++){
        if(!visited[e] && active[e]){
            dfs(e);
            numComponents++;
        }
    }
    cout << numComponents << endl;
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