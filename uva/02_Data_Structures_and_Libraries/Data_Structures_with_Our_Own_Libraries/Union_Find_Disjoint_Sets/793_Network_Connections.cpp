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


int caso = 0;
string lineP;

void solve(){
    char type;
    int n,a,b;
    int success = 0,unsuccess = 0;
    cin>>n;
    DSU DSU(n);
    cin.ignore();
    while(getline(cin,lineP)){
        if(lineP.length() == 0) break;
        stringstream ss(lineP);
        ss >> type >> a >> b;
        a--,b--;
        if(type == 'c'){
            DSU.unionSet(a,b);
        }else{
            if(DSU.isSameSet(a,b)) success++;
            else unsuccess++;
        }

    }
    cout << success << "," << unsuccess << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t; cin>>t;
    cin.ignore();
    getline(cin,lineP);
    while(t--){
        solve();
        if(t != 0) cout << endl;
    }
    return 0;
}