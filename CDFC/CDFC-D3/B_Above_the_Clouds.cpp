/*
==========================================================
|  Archivo       : B_Above_the_Clouds.cpp
|  Autor         : Russell
|  Fecha         : 2025-06-17 10:52
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Tema 1
|  - Tema 2
|  - Tema 3
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
    string s; cin>>s;
    if(n == 3){
        if(s[1] == s[0] || s[1] == s[2]){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
        
    }else{
        map<char, int> left, right;
        for(int e = 0 ;e < n-1 ; e++){
            left[s[e]]++;
        }
        for(int e = 1;e< n ;e++){
            right[s[e]]++;
        }
        bool ans = false;
        for(auto [c,count]: left){
            // cout <<  c << " " << count << endl;
            ans |= (count >=2);
        }
        for(auto [c,count]: right){
            ans |= (count >=2);
        }
        cout << (ans?"Yes\n":"No\n");
    }
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