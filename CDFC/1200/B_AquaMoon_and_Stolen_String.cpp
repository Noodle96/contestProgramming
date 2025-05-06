/*
==========================================================
|  Archivo       : B_AquaMoon_and_Stolen_String.cpp
|  Autor         : Russell
|  Fecha         : 2025-05-06 16:20
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Interactive
|  - Math
|  - *1200
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
string str;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> vecfreq(m, vector<int>(26,0));
    int total = n;
    while(total--){
        cin>>str;
        for(int i = 0; i < m; i++){
            vecfreq[i][str[i]-'a']++;
        }
    }
    total = n;
    total -= 1;
    while(total--){
        cin>>str;
        for(int i = 0; i < m; i++){
            vecfreq[i][str[i]-'a']--;
        }
    }
    for(int e = 0 ; e < m; e++){
        for(int j = 0 ;j < 26 ; j++){
            if(vecfreq[e][j] > 0){
                cout<<char(j+'a');
                break;
            }
        }
    }
    cout << endl;
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