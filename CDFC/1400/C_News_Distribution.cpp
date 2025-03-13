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
using vi = vector<int>;

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
        vi parent, rank, sizeSet;
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

int trash;

void solve(){
    int n,m; cin>>n>>m;
    DSU dsu(n);
    while(m--){
        int k; cin>>k;
        if(k >= 2){
            int first; cin>>first; first--;
            for(int e = 1 ;e < k ; e++){
                int other; cin>>other; other--;
                dsu.unionSet(first,other);
            }
        }else if(k == 1){
            cin>>trash; // only one person
        }else{
            // k == 0
        }
    }
    // ver cuantos intgerantes hay en cada grupo
    for(int e = 0; e < n; e++){
        if(e == n-1) cout << dsu.sizeOfSet(e) << endl;
        else cout << dsu.sizeOfSet(e) << " ";
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