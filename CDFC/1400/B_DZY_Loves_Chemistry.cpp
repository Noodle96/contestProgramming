/*
==========================================================
|  Archivo       : B_DZY_Loves_Chemistry.cpp
|  Autor         : Russell
|  Fecha         : 2025-10-21 14:00
|--------------------------------------------------------
|  Tópicos utilizados:
|  - training
|  - dfs and similar
|  - dsu
|  - greedy
|  - *1400
==========================================================
*/

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;

using ll = long long;
using i64 = int64_t;
using i32 = int32_t;
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

const int INF = 1e9;

ll gcd(ll a,ll b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}
ll floordiv(ll a, ll b) {
    if (a >= 0) return a / b;
    return - ( (-a + b - 1) / b );
}
ll ceildiv(ll a, ll b) {
    // ceil(a/b) = -floor((-a)/b)
    if (a >= 0) return (a + b - 1) / b;
    return - ( (-a) / b );
}
int bitlen_unsigned(unsigned long long n){
    // __builtin_clzll: Cuenta los ceros a la izquierda
    return (n == 0) ? 1 : 64 - __builtin_clzll(n);
}

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

class Dsu{
    private:
        vector<int> p, rank, setSize;
        int numSets;
    public:
        Dsu(int N){
            p.assign(N,0);
            for(int i = 0; i < N; i++) p[i] = i;
            rank.assign(N,0);
            setSize.assign(N,1);
            numSets = N;
        }
        ~Dsu(){};
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
void solve2(){
    int a = 14;
    cout << (1LL << a) << endl;
}

void solve(){
    i32 n, m; cin >> n >> m;
    Dsu dsu(n);
    while(m--){
        i32 u,v; cin >> u >> v;
        u--; v--;
        dsu.unionSet(u,v);
    }
    cout << (1LL << (n-dsu.numDisjointSets())) << endl;
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