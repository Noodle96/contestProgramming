/*
==========================================================
|  Archivo       : B_Coins.cpp
|  Autor         : Russell
|  Fecha         : 2025-10-03 17:38
|--------------------------------------------------------
|  Tópicos utilizados:
|  - training
|  - *1300
|  - math
|  - greedy
==========================================================
*/

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
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
using vll = vector<ll>;

#define pb push_back
#define mp make_pair

const ll INF = 1e18;

ll gcd(ll a,ll b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

void solve(){
    int n; cin >> n;
    auto canonical_desc = [&](int x) -> vector<int>{
        vector<int> res;
        for(int i = 2; i*i <= x;i++){
            while(x%i == 0){
                res.pb(i);
                x /= i;
            }
        }
        if(x > 1) res.pb(x);
        sort(all(res), [](int a, int b){
            // ordena de menor a mayor
            return a < b;
        });
        return res;
    };
    vector<int> d = canonical_desc(n);
    int curr = n;
    for(auto x: d){
        cout << curr << " ";
        curr /= x;
    }
    cout << 1 << endl;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;
    //cin >> t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}