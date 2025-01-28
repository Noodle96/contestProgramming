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

vector<int> getFactors(int n){
    vector<int> ans;
    for(int e = 2; e <= sqrt(n); e++){
        while(n % e == 0){
            ans.pb(e);
            n /= e;
        }
    }
    if(n > 1) ans.pb(n);
    return ans;
}

void solve(){
    int n;
    while(cin>>n){
        if(n != 0){
            cout << n << " = ";
            if(n < 0) cout << "-1 x ";
            n = abs(n);
            vector<int> factors = getFactors(n);
            for(int e  = 0 ; e < factors.size()-1; e++){
                cout << factors[e] << " x ";
            }
            cout << factors.back() << endl;
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