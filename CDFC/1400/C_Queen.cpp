/*
==========================================================
|  Archivo       : C_Queen.cpp
|  Autor         : Russell
|  Fecha         : 2025-09-19 17:06
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Dfs and similar
|  - Trees
|  - Training
|  - *1400
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
int n;
vector<int> parent;
int root = -1;
vector<vector<int>> adj;
vector<int> respects;
vector<bool> visited;
vector<int> totalChildren;
vector<int> totalChildrenRespect;

void dfs(int u){
    if(visited[u]) return;
    visited[u] = true;
    int totalChild = 0;
    int totalChildRes = 0;
    for(auto v: adj[u]){
        if(!visited[v]){
            dfs(v);
            totalChild++;
            totalChildRes += respects[v];
        }
    }
    totalChildren[u] = totalChild;
    totalChildrenRespect[u] = totalChildRes;
}

void solve(){
    cin >> n;
    parent.assign(n, 0);
    adj.assign(n, vector<int>());
    respects.assign(n, 0);
    visited.assign(n, false);
    totalChildren.assign(n, 0);
    totalChildrenRespect.assign(n, 0);
    for(int i = 0 ; i < n; i++){
        int pi, ci; cin >> pi >> ci;
        respects[i] = ci;
        parent[i] = pi-1;
        if(pi == -1) root = i;
        if(pi != -1){
            adj[pi-1].pb(i);
            adj[i].pb(pi-1);
        }
    }
    // cout << "before root" << endl;
    dfs(root);

    // // ver la cantidad de hijos y hijos que respetan a asu padre de cada nodo
    // for(int i = 0 ;i < n ; i++){
    //     cout << "total children of " << i+1 << ": " << totalChildren[i] << " totoal children that respect " << totalChildrenRespect[i] << "\n";
    // }

    vector<int> childrenDeleted;
    // Procedemos con la eliminacion de nodos desde el menor hasta el mayor
    for(int i = 0 ; i < n; i++){
        if( i == root) continue;
        int p = parent[i];
        /*
            Para poder elmiminar un nodo, dicho nodo tiene que respectar a su
            padre(respeta a todo sus ancestros) respects[i] == 1 && todos sus hijos
            tienen que respectarlo (totalChildrenRespect[i] == totalChildren[i])

        */
        if( respects[i] == 1 && totalChildren[i] == totalChildrenRespect[i]){
            // Eliminar nodo, ahora el padre tiene un hijo menos
            totalChildren[p]--;
            totalChildrenRespect[p] -= respects[i];

            // ahora los hijos del nodo eliminado pasan a ser hijos del padre
            totalChildren[p] += totalChildren[i];
            totalChildrenRespect[p] += totalChildrenRespect[i];
            childrenDeleted.pb(i+1);
        }
    }

    // print ans
    if(childrenDeleted.size() == 0) cout << "-1\n";
    else
        for(auto x: childrenDeleted) cout << x << " ";
        cout << "\n";
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