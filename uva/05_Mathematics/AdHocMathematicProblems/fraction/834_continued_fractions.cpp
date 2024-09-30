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
ll num,den;
void solve(){
    while(cin>>num>>den){
        // cout << num << " " << den << endl;
        vector<ll> ans;
        while(num % den != 0){
            ans.pb(num/den);
            ll resto = num%den;
            num = den;
            den = resto;
        }
        ans.pb(num/den);
        if(ans.size() == 1){
            cout << "[" << ans[0] << "]" << endl;
        }else{
            cout << "[" << ans[0] << ";";
            for(ll e = 1; e < ans.size()-1; e++){
                cout << ans[e] << ",";
            }
            cout << ans[ans.size()-1] << "]" << endl;
        }
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