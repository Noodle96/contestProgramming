/*
==========================================================
|  Archivo       : C_Cake_Assignment.cpp
|  Autor         : Russell
|  Fecha         : 2025-09-08
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Manipulacion de bits
==========================================================
*/

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;

using ll = long long;
using i128 = __int128;
using ui128 = unsigned __int128;
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
    ll k,x; cin >> k >> x;
    i128 T128 = (ui128)1 << (k + 1);
    ull T = (ull)T128;
    ull mid = 1ULL << k;
    ull y = (ull)x;

    if (y == mid) {
        cout << 0 << endl;
        return;
    }
    vector<int> rev_ops;
    while (y != mid) {
        if (y < mid) {
            rev_ops.pb(1); // Chocola da su mitad
            y <<= 1;       // entonces, previo y = 2*y
        } else {
            rev_ops.push_back(2); // Vanilla da su mitad a chocola
            y = (y << 1) - T;     // entonces, previo y = 2*y - T
        }
    }
    int n = (int)rev_ops.size();
    cout << n << endl;
    for (int i = n - 1; i >= 0; --i) {
        cout << rev_ops[i] << (i ? ' ' : '\n');
    }
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