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

/*
    SOLVE mediante el principio del palomar
*/

void solve(int caso){
    int n; cin>>n;
    map<int,int> map;
    for(int e = 0 ; e < n ; e++){
        for(int j = 0; j < n; j++){
            int temp; cin>>temp;
            map[temp]++;
        }
    }
    for(auto it = map.begin() ; it != map.end(); it++){
        if(it->second > n){
            cout << "Case " << caso << ": no" << endl;
            return;
        }
    }
    cout << "Case " << caso << ": yes" << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t; cin>>t;
    int caso = 1;
    while(t--){
        solve(caso++);
    }
    return 0;
}