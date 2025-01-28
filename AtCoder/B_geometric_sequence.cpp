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
const float inf = 1e9;
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
    int n; cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    if(n == 2){
        cout << "Yes" << endl;
        return;
    }
    auto findZero = find(all(a),0);
    if(findZero != a.end()){
        cout << "No" << endl;
        return;
    }
    auto ans = true;
    for(int e = 0; e < n-2  ; e++){
        bool temp = a[e+1]*a[e+1] == a[e]*a[e+2];
        ans = ans && temp;
    }
    cout << (ans ? "Yes" : "No") << endl;

}
void solve2(){
    vector<int> vec = {1,2,3,4,5,6,7,8,9,10};
    auto f = find(vec.begin(), vec.end(), 5);
    if(f != vec.end()){
        cout << "any" << endl;
    }else{
        cout << "any2" << endl;
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
    // solve2();
    return 0;
}