/*
==========================================================
|  Archivo       : A_Reposts.cpp
|  Autor         : Russell
|  Fecha         : 2025-08-24 13:58
|--------------------------------------------------------
|  Tópicos utilizados:
|  - *1200
|  - DFS: max len component
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

void toLower(string &s){
    for(auto &c : s) c = tolower(c);
}

vector<vector<int>> adj;
int maxDepth = 0;

void dfs(int u, int depth){
    maxDepth = max(maxDepth, depth);
    for(auto v : adj[u]){
        dfs(v, depth+1);
    }
}

void solve(){
    int n; cin >> n;
    int index = 0;
    unordered_map<string, int> names;

    adj.assign(n+1, vector<int>());
    for(int e = 0 ; e < n; e++){
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        toLower(s1);
        toLower(s3);
        if(names.find(s1) == names.end()){
            names[s1] = index++;
        }
        if(names.find(s3) == names.end()){
            names[s3] = index++;
        }
        adj[names[s3]].pb(names[s1]);
    }
    dfs(names["polycarp"], 1);
    cout << maxDepth << "\n";
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