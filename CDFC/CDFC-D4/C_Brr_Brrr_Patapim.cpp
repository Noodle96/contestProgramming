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

const int N = 808;
int grid[N][N];

void solve(){
    int n; cin>>n;
    for(int e = 0 ;e < n ; e++){
        for(int j = 0 ;j < n ; j++){
            cin>>grid[e][j];
        }
    }
    vector<int> ans(2*n,0);
    for(int e = 0 ;e < n ; e++){
        for(int j = 0 ;j < n ; j++){
            ans[e+j+1] = grid[e][j];
        }
    }
    int sumatotal = accumulate(ans.begin(),ans.end(),0);
    ans[0] = (2*n)*(2*n+1)/2 - sumatotal;
    for(int e = 0 ;e < 2*n ; e++){
        cout<<ans[e]<<" ";          
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