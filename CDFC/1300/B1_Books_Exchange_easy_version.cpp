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
        vector<int> p,rank,setSize;
        int numSets;
    public:
        DSU(int N){
            p.assign(N,0);
            for(int i = 0 ; i < N; i++) p[i] = i;
            rank.assign(N,0);
            setSize.assign(N,1);
            numSets = N;
        }
        int findSet(int i){
            return (p[i] == i) ? i : (p[i] = findSet(p[i]));
        }
        bool isSameSet(int i, int j){
            return findSet(i) == findSet(j);
        }
        int numDisjointSets(){
            return numSets;
        }
        int sizeOfSet(int i){
            return setSize[findSet(i)];
        }
        void unionSet(int i, int j){
            if(isSameSet(i,j)) return;
            int x = findSet(i), y = findSet(j);
            if(rank[x] > rank[y]){
                p[y] = x;
                setSize[x] += setSize[y];
            }else{
                p[x] = y;
                setSize[y] += setSize[x];
                if(rank[x] == rank[y]) ++rank[y];
            }
            --numSets;
        }
};

void solve(){
    int n; cin>>n;
    vector<int> p(n);
    for(auto &x:p) cin >> x, x--;
    DSU dsu(n);
    for(int e = 0 ;e < n ; e++){
        if(dsu.sizeOfSet(e) == 1){
            auto first = p[e];
            auto second = p[first];
            while(!dsu.isSameSet(first, second)){
                dsu.unionSet(first, second);
                first = second;
                second = p[first];
            }
        }
    }
    for(int e = 0; e < n; e++){
        cout << dsu.sizeOfSet(e) << " ";
    }cout << endl;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t; cin>>t;
    while(t--) solve();
    return 0;
}