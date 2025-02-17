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
        vector<int> rank,p;
        int numSets;
    public:
        vector<int> setSize;
        DSU(int N){
            rank.assign(N,0);
            p.assign(N,0);
            for(int i = 0; i < N; i++) p[i] = i;
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
        int numDisjointSets(){
            return numSets;
        }
        void pathCompresion(){
            for(int e = 0 ;e < rank.size() ; e++) findSet(e);
        } 
};


void solve(){
    int n,m;
    while(cin>>n>>m){
        if(n == 0 && m == 0) break;
        DSU DSU(n);
        for(int e = 0 ; e < m; e++){
            int total ; cin>>total;
            int first; cin>>first;
            if(total >= 2){
                for(int j = 1;j < total ; j++){
                    int next; cin>>next;
                    DSU.unionSet(first,next);
                }
            }
            
        }
        cout << DSU.setSize[DSU.findSet(0)] << endl;
        
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