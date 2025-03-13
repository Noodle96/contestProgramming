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
        vector<int> parent, rank, sizeSet;
        int numSets;
    public:
        DSU(int n){
            parent.assign(n,0);
            iota(all(parent),0);
            rank.assign(n,0);
            sizeSet.assign(n,1);
            numSets = n;
        }
        int findSet(int i){
            return (parent[i] == i) ? i : (parent[i] = findSet(parent[i]));
        }
        bool isSameSet(int i, int j){
            return (findSet(i) == findSet(j));
        }
        int numDisjointSets(){
            return numSets;
        }
        int sizeOfSet(int i){
            return sizeSet[findSet(i)];
        }
        void unionSet(int i, int j){
            if(isSameSet(i,j)) return;
            int x = findSet(i);
            int y = findSet(j);
            if(rank[x] > rank[y]){
                parent[y] = x;
                sizeSet[x] += sizeSet[y];
            }else{
                parent[x] = y;
                sizeSet[y] += sizeSet[x];
                if(rank[x] == rank[y]) rank[y]++;
            }
            numSets--;
        }
};


void solve(){
    int n, m1,m2; cin>>n>>m1>>m2;
    DSU dsu1(n), dsu2(n);
    for(int e = 0 ;e < m1 ; ++e){
        int a,b; cin>>a>>b; a--;b--;
        dsu1.unionSet(a,b);
    }
    for(int e = 0 ;e < m2 ; ++e){
        int a,b; cin>>a>>b; a--;b--;
        dsu2.unionSet(a,b);
    }
    vector<pair<int,int>> ans;
    for(int e = 0 ; e < n; e++){
        for(int j = 0 ; j < n ; j++){
            if(e != j){
                if(!dsu1.isSameSet(e,j) && !dsu2.isSameSet(e,j)){
                    ans.pb({e+1,j+1});
                    dsu1.unionSet(e,j);
                    dsu2.unionSet(e,j);
                }
            }
        }
    }
    cout << ans.size() << endl;
    for(auto [a,b]: ans){
        cout << a << " " << b << endl;
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