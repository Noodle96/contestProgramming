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

int N,T;
vector<int> divisores;


void divisoresTotal(int n){
    for(int i = 1; i*i <= n; i++){
        if(n%i == 0){
            divisores.pb(i);
            if(i != n/i) divisores.pb(n/i);
        }
    }
    // cout<< "total: "<<divisores.size() << endl;
    // for(int i = 0; i < divisores.size(); i++){
    //     cout << divisores[i] << " ";
    // }cout << endl;
}

void solve(){
    cin>>N>>T;
    if(T == 1){
        cout << N << endl;
        return;
    }
    divisores.clear();
    int cont = 0;
    divisoresTotal(T-1);
    for(auto e : divisores){
        if(e <= N) cont++;
    }
    cout << cont << endl;
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