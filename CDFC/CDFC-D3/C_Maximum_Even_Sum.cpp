/*
==========================================================
|  Archivo       : C_Maximum_Even_Sum.cpp
|  Autor         : Russell
|  Fecha         : 2025-09-07 10:07
|--------------------------------------------------------
|  Tópicos utilizados:
|  - math
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


string to_string_int128(__int128 x) {
    if (x == 0) return "0";
    bool neg = x < 0;
    if (neg) x = -x;
    string s;
    while (x > 0) {
        int d = int(x % 10);
        s.push_back(char('0' + d));
        x /= 10;
    }
    if (neg) s.push_back('-');
    reverse(s.begin(), s.end());
    return s;
}

void solve(){
    ll a, b; 
    cin >> a >> b;
    __int128 P = (__int128)a * (__int128)b;

    if ((a % 2) == 0) {
        if (b % 2 == 1) {
            cout << -1 << "\n";
        } else {
            __int128 ans = P/2 + 2; // k = b/2
            cout << to_string_int128(ans) << endl;
        }
    } else { // a impar
        int v = 0;
        ll bb = b;
        while ((bb % 2) == 0) { v++; bb >>= 1; }
        if (v == 0) {
            __int128 ans = P + 1; // k = b
            cout << to_string_int128(ans) << "\n";
        } else if (v == 1) {
            cout << -1 << "\n";
        } else { // v >= 2
            __int128 ans = P/2 + 2; // k = b/2
            cout << to_string_int128(ans) << "\n";
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t; cin >> t;
    while(t--) solve();
    return 0;
}