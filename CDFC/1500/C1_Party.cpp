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

enum Status{
    UNFRIENDLY = 0,
    FRIENDLY = 1,
};

class DSU{
    private:
        vector<int> parent, rank, size;
        int numSets;
        vector<Status> status;
    public:
        DSU(int N){
            parent.assign(N,0);
            iota(all(parent),0);
            rank.assign(N,0);
            size.assign(N,1);
            numSets = N;
            status.assign(N,FRIENDLY);
        }
        int findSet(int i){
            return (parent[i] == i) ? i : (parent[i] = findSet(parent[i]));
        }
        bool isSameSet(int i, int j){
            return findSet(i) == findSet(j);
        }
        void unite(int i, int j){
            if(!isSameSet(i,j)){
                int x = findSet(i), y = findSet(j);
                if(rank[x] > rank[y]){
                    parent[y] = x;
                    size[x] += size[y];
                }else{
                    parent[x] = y;
                    size[y] += size[x];
                    if(rank[x] == rank[y]) rank[y]++;
                }
                numSets--;
            }
        }
        int numDisjointSets(){
            return numSets;
        }
        int sizeOfSet(int i){
            return size[findSet(i)];
        }
        void pathCompression(){
            for(int i = 0 ; i < parent.size(); i++){
                findSet(i);
            }
        }
        void setUnfriendlyStatus(int i){
            int x = findSet(i);
            status[x] = UNFRIENDLY;
        }
        Status getStatus(int i){
            return status[findSet(i)];
        }
};


void solve(){
    int n,m,k,u,v;
    cin>>n>>k;
    DSU dsu(n);
    while(k--){
        cin>>u>>v;
        u--;v--;
        dsu.unite(u,v);
    }
    cin>>m;
    while(m--){
        cin>>u>>v;
        u--;v--;
        if(dsu.isSameSet(u,v)){
            dsu.setUnfriendlyStatus(u);
        }
    }
    // cout << "Leido corr" << endl;
    int maxLenConnectedComponent = 0;
    for(int e = 0 ; e < n;e++){
        if(dsu.sizeOfSet(e) > maxLenConnectedComponent && dsu.getStatus(e) == FRIENDLY){
            maxLenConnectedComponent = dsu.sizeOfSet(e);
        }
    }
    cout << maxLenConnectedComponent << endl;
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