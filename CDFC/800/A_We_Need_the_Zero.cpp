/*
==========================================================
|  Archivo       : A_We_Need_the_Zero.cpp
|  Autor         : Russell
|  Fecha         : 2025-04-18 10:42
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Bitmask
|  - Brute Force
|  - *800
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
    int n; cin>>n;
    vector<int> ai(n);
    for(int e = 0 ; e < n; e++) cin>>ai[e];
    for(int x = 0; x < (1 << 8); x++){
        vector<int> bi(n);
        for(int e = 0 ;e < n ; e++){
            bi[e] = ai[e] ^ x;
        }
        auto ans = bi[0];
        for(int e = 1 ;e < n ; e++){
            ans ^= bi[e];
        }
        if(ans == 0){
            cout<<x<<endl;
            return;
        }
    }
    cout << "-1" << endl;
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