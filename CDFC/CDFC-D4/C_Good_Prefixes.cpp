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

int gcd(int a,int b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
int n;
void solve(){
    ll contTotal = 0;
    cin>>n;
    vector<ll> vec(n),sumPrefixes(n,0);
    for(auto &x : vec)cin>>x;
    sumPrefixes[0] = vec[0];
    for(int e = 1; e < n; e++) sumPrefixes[e] = sumPrefixes[e-1] + vec[e];
    // cout << "print prefix" << endl;
    // for(auto e: sumPrefixes){
    //     cout << e << " ";
    // }cout << endl;
    set<ll> set;
    int index = 0;
    for(auto val: sumPrefixes){
        set.insert(vec[index++]);
        if(val%2 == 0){
            auto f = set.find(val/2);
            if(f != set.end()){
                // cout << "encontro para: " << val<< endl;
                contTotal++;
            }
        }
    }
    cout << contTotal << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t; cin>>t;
    while(t--)solve();
    return 0;
}