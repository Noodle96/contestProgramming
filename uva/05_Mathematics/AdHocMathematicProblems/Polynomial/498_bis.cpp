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
ll x;

long long Pow(long long x, long long y) {
    if(y == 0)
        return 1;
    if(y&1)
        return x*Pow(x*x, y/2);
    else
        return Pow(x*x, y/2);
}

void solve(){
    while(cin>>x){
        string A;
        cin.ignore();
        getline(cin,A);
        vector<ll> a;
        stringstream ss(A);
        ll temp;
        while(ss >> temp){
            a.pb(temp);
        }
        ll len = a.size();
        ll ans = 0;
        for(ll e = 0 ; e < len-1; e++){
            ans += (a[e] * (len-1-e) * Pow(x,len-2-e));
        }
        cout << ans << endl;
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