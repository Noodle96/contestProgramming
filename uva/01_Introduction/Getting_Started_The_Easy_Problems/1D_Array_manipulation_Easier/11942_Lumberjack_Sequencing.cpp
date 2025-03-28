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

void solve(){
    vector<int> vec(10);
    for(int e = 0 ; e < 10; e++)cin>>vec[e];
    bool asc = true, desc = true;
    for(int e = 1; e < 10; e++){
        asc &= (vec[e] >= vec[e-1]);
        desc &= (vec[e] <= vec[e-1]);
    }
    cout << (asc || desc ? "Ordered" : "Unordered") << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t; cin>>t;
    cout << "Lumberjacks:" << endl;
    while(t--)solve();
    return 0;
};