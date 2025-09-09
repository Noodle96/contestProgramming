/*
==========================================================
|  Archivo       : A.cpp
|  Autor         : Russell
|  Fecha         : 2025-06-12 09:30
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
    int n,k;
    cin>>n>>k;
    if(n <= 3){
        for(int e = 0 ;e < k ; e++){
            cout << 1;
        }
        for(int e = 0 ; e < (n-k); e++){
            cout << 0;
        }cout << endl;
    }else{
        // cout << "n: " << n << " k: " << k << endl;
        deque<char> ans;
        if(n != k) ans.push_front('0');
        else ans.push_front('1');
        for(int e = 0; e < k-1; e++ ){
            ans.push_front('1');
        }
        for(int e = 0;e < (n-k-1) ; e++){
            ans.push_front('0');
        }
        if(k == 0){}
        else ans.push_front('1');
        for(int e = 0 ; e < n ; e++){
            cout << ans[e];
        }cout << endl;
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