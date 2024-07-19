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
map<ll, vector<ll>> mapa;
vector<ll> weight;
void solve(){
    cin>>n;
    for(ll e = 1 ; e  <= n; e++){
        ll a;
        cin>>a;
        mapa[a].pb(e);
    }
    for(int e = 0 ; e < n; e++){
        ll a;
        cin>>a;
        weight.pb(a);
    }
    ll granTotal = 0;
    for(auto it = mapa.begin(); it != mapa.end(); it++){
        if(it->second.size() >= 2){
            ll total =  0;
            ll maximo = LLONG_MIN;
            for(auto e: it->second){
                total += weight[e-1];
                if(weight[e-1] > maximo){
                    maximo = weight[e-1];
                }
            }
            total -= maximo;
            granTotal += total;
        }
    }
    cout << granTotal << endl;

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