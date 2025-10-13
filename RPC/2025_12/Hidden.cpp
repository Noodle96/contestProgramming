/*
==========================================================
|  Archivo       : Hidden.cpp
|  Autor         : Russell
|  Fecha         : 2025-10-11 14:48
|--------------------------------------------------------
|  Tópicos utilizados:
|  - rpc
|  - implementation
|  - data structures
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
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    string ans = "";
    while(!s1.empty() || !s2.empty() || !s3.empty()){
        map<char, int> cnt;
        if(s1.size() >= 1){
            cnt[s1[0]]++;
        }
        if(s2.size() >= 1){
            cnt[s2[0]]++;
        }
        if(s3.size() >= 1){
            cnt[s3[0]]++;
        }
        auto first = *cnt.begin();
        auto second = *next(cnt.begin());
        if(first.second > second.second){
            ans += first.first;
            if(first.first == '1'){
                s2.erase(s2.begin());
                s3.erase(s3.begin());
            }else if(first.first == '2'){
                s1.erase(s1.begin());
                s3.erase(s3.begin());
            }else{
                s1.erase(s1.begin());
                s2.erase(s2.begin());
            }
        }else{
            ans += second.first;
            if(second.first == '1'){
                s2.erase(s2.begin());
                s3.erase(s3.begin());
            }else if(second.first == '2'){
                s1.erase(s1.begin());
                s3.erase(s3.begin());
            }else{
                s1.erase(s1.begin());
                s2.erase(s2.begin());
            }
        }
        // cout << "\t" << ans << endl;
    }
    cout << ans << endl;

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