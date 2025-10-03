/*
==========================================================
|  Archivo       : A_Chat_room.cpp
|  Autor         : Russell
|  Fecha         : 2025-10-03 17:29
|--------------------------------------------------------
|  Tópicos utilizados:
|  - training
|  - *1000
|  - string
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
    string s; cin >> s;
    string hello = "hello";
    int h_i = 0;
    for(int j = 0 ; j < s.size(); j++){
        if(s[j] == hello[h_i] ){
            h_i++;
            if(h_i == 5){
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";

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