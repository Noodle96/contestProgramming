/*
==========================================================
|  Archivo       : Encrypting.cpp
|  Autor         : Russell
|  Fecha         : 2025-10-11
|--------------------------------------------------------
|  Tópicos utilizados:
|  - rpc
|  - implementation
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
    int N;  cin >> N;
    string r0, r1;
    cin >> r0 >> r1;

    string ans;
    for (int c = 0; c < N; ){
        bool emptyCol = (r0[c] == '.' && r1[c] == '.');
        if (emptyCol) { 
            ++c; 
            continue; 
        }
        int j = c;
        while (j < N && !(r0[j] == '.' && r1[j] == '.')) ++j;
        int width = j - c;

        if (width == 4) ans.pb('v');
        else if (width == 8) ans.pb('w');
        c = j;
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