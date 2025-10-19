/*
==========================================================
|  Archivo       : A_notelock.cpp
|  Autor         : Russell
|  Fecha         : 2025-10-19 10:03
|--------------------------------------------------------
|  Tópicos utilizados:
|  - div2
==========================================================
*/

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;

using ll = long long;
using i64 = int64_t;
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

const int INF = 1e9;

ll gcd(ll a,ll b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}
ll floordiv(ll a, ll b) {
    if (a >= 0) return a / b;
    return - ( (-a + b - 1) / b );
}
ll ceildiv(ll a, ll b) {
    // ceil(a/b) = -floor((-a)/b)
    if (a >= 0) return (a + b - 1) / b;
    return - ( (-a) / b );
}
int bitlen_unsigned(unsigned long long n){
    // __builtin_clzll: Cuenta los ceros a la izquierda
    return (n == 0) ? 1 : 64 - __builtin_clzll(n);
}

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

void solve(){
    int n,k; cin >> n >> k;
    string s; cin >> s;
    vector<int> prefixSum(n+1,0);
    for(int i = 0; i < n; i++){
        prefixSum[i+1] = prefixSum[i] + (s[i] == '1' ? 1 : 0);
    }
    int bloqueados = 0;
    for (int i = 0; i < n; ++i){
        if (s[i] != '1') continue;

        int L = max(0, i-(k-1));
        int R = i-1;
        int onesPrev = (R >= L) ? (prefixSum[R+1] - prefixSum[L]) : 0;

        if (onesPrev == 0) ++bloqueados;
    }
    cout << bloqueados << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;
    cin >> t;
    // t = 1;
    while(t--){
        solve();
    }
    return 0;
}