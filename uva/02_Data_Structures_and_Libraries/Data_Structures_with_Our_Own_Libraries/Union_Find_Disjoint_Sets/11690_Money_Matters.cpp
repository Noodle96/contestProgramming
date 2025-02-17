#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define msg(str,str2) cout << str << str2<< endl
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

#define pb push_back
#define mp make_pair

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
        vector<int> p, rank, setSize;
        int numSets;
    public:
        DSU(int N){
            p.assign(N,0);
            for(int i = 0; i < N; i++) p[i] = i;
            rank.assign(N,0);
            setSize.assign(N,1);
            numSets = N;
        }
        ~DSU(){};
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
        void pathCompression(){
            for(int e = 0 ; e < p.size(); e++) findSet(e);
        }
        void unionSet(int i, int j){
            if(!isSameSet(i,j)){
                int x = findSet(i);
                int y = findSet(j);
                if(rank[x] > rank[y]){
                    p[y] = x;
                    setSize[x] += setSize[y];
                }else{
                    p[x] = y;
                    setSize[y] += setSize[x];
                    if(rank[x] == rank[y]) rank[y]++;
                }
                numSets--;
            }
        }
};

void solve(){
    int n,m;
    cin>>n>>m;
    DSU DSU(n);
    vector<int> deuda(n);
    for(int e = 0 ; e < n; e++) cin>>deuda[e];
    for(int e = 0 ; e < m; e++){
        int a,b;
        cin>>a>>b;
        DSU.unionSet(a,b);
    }
    DSU.pathCompression();
    map<int, vector<int> > mapa;
    for(int e = 0; e < n; e++){
        int p = DSU.findSet(e);
        mapa[p].pb(e);
    }
    // cout << "print map" << endl;
    // for(auto it = mapa.begin() ; it != mapa.end(); it++){
    //     cout << "p: " << it->first << endl;
    //     for(auto et = it->second.begin();  << endl;;et != it->second.end(); et++){
    //         cout << *et << " ";
    //     }cout << endl;
    // }
    // cout <<"size: " <<  mapa.size() << endl;
    bool ans= true;
    for(auto it = mapa.begin() ;it != mapa.end() ; it++){
        int suma = 0;
        for(auto et = it->second.begin() ; et != it->second.end(); et++){
            suma += deuda[*et];
        }
        ans &= (suma == 0);
    }
    cout << (ans?"POSSIBLE":"IMPOSSIBLE") << endl;
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