/*
==========================================================
|  Archivo       : D_Slavic_s_Exam.cpp
|  Autor         : Russell
|  Fecha         : 2025-06-13 18:46
|--------------------------------------------------------
|  Tópicos utilizados:
|  - string
|  - implementation
|  - *1100
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
    string s, t;
    cin>>s>>t;
    int i_t = 0;
    for(;i_t < t.size() ; i_t++){
        for(int i_s = 0; i_s < s.size() && i_t < t.size(); i_s++){
            if(s[i_s] == '?'){
                s[i_s] = t[i_t];
                i_t++;
            }else if(s[i_s] == t[i_t]){
                i_t++;
            }else{
                // i_s -= 1;
            }
        }
        if(i_t < t.size()){
            cout << "NO\n";
            return;
        }
    }
    // termino t bien
    for(auto &c: s){
        if(c == '?') c = 'a';
    }
    cout << "YES\n";
    cout << s << "\n";
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