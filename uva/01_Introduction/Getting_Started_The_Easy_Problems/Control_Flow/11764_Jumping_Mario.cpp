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
int caso = 1;

void solve(){
    int n; cin>>n;
    vector<int> vec(n);
    for(int e = 0 ; e < n; e++) cin>> vec[e];
    int hight_jump = 0, low_jump = 0;
    for(int e = 0 ; e < n-1; e++){
        if(vec[e] > vec[e+1]) low_jump++;
        else if(vec[e] < vec[e+1]) hight_jump++;
    }
    cout << "Case " << caso++ << ": " << hight_jump << " " << low_jump << endl;

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