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

class DSU{
    private:
        vector<int> parent, size, rank;
        int numSets;
    public:
        DSU(int n){
            parent.assign(n,0);
            size.assign(n,1);
            rank.assign(n,0);
            numSets = n;
            for(int e = 0 ; e < n; e++) parent[e] = e;
        }
        int findSet(int v){
            return parent[v] == v ? v : parent[v] = findSet(parent[v]);
        }
        bool isSameSet(int a, int b){
            return findSet(a) == findSet(b);
        }
        void unionSet(int a, int b){
            int x = findSet(a);
            int y = findSet(b);
            if(!isSameSet(x,y)){
                numSets--;
                if(rank[x] > rank[y]){
                    parent[y] = x;
                    size[x] += size[y];
                }else{
                    parent[x] = y;
                    size[y] += size[x];
                    if(rank[x] == rank[y]) rank[y]++;
                }
            }
        }
        int numDisjointSets(){
            return numSets;
        }
        int sizeOfSet(int v){
            return size[findSet(v)];
        }
};


void solve(){
    int n,m; cin>>n>>m;
    DSU dsu(n);
    int numUnions = 0;
    while(m--){
        int a,b; cin>>a>>b;
        a--;b--;
        if(dsu.isSameSet(a,b)) numUnions++;
        dsu.unionSet(a,b);
    }
    if(numUnions == 1 && dsu.numDisjointSets() == 1){
        cout  << "FHTAGN!" << endl;
    }else cout << "NO" << endl;
    // cout << numUnions << " " << dsu.numDisjointSets() << endl;
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