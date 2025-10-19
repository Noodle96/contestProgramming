/*
==========================================================
|  Archivo       : B_Make_it_Zigzag.cpp
|  Autor         : Russell
|  Fecha         : 2025-10-19 12:24
|--------------------------------------------------------
|  Tópicos utilizados:
|  - div 2
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
    int n; cin >> n;
    // cout <<"caso; " << n  << endl;
    vector<i64> a(n);
    vector<i64> max_pref(n);
    i64 Max = -1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        Max = max(Max, a[i]);
        max_pref[i] = Max;
    }
    // cout << "prefix max array: " << endl;
    // for(int i = 0 ; i < n; i++){
    //     cout << max_pref[i] << " ";
    // }
    // cout << endl;
    for(int i = 1; i < n; i+=2)
        a[i] = max_pref[i];
    // cout << "final array 1: " << endl;
    // for(int i = 0 ; i < n; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    int ans = 0;
    for(int i = 0; i < n - 1; i++){
        if(i%2 == 0){ // indices pares
            if(a[i]  == a[i+1]){
                a[i]--;
                ans++;
                // cout << "ans: " << ans << " i: " << i << endl;
            }
        }else{// indices impares
            if(a[i] <= a[i+1]){
                ans  += (a[i+1]- (a[i]-1));
                a[i+1] = a[i]-1;
                // cout << "ans: " << ans << " i: " << i << endl;

            }
        }
    }
    // cout << "final array 2: " << endl;
    // for(int i = 0 ; i < n; i++){
    //     cout << a[i] << " ";
    // }
    // cout << endl << endl;
    // cout  << "ans: " << ans << endl;
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
    cin >> t;
    // t = 1;
    while(t--){
        solve();
    }
    return 0;
}