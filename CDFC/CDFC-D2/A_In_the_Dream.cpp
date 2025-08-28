/*
==========================================================
|  Archivo       : A_In_the_Dream.cpp
|  Autor         : Russell
|  Fecha         : 2025-08-28 09:52
|--------------------------------------------------------
|  Tópicos utilizados:
|  - math
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

bool ok(int x, int y) {
    int big = max(x, y), small = min(x, y);
    return big <= 2 * (small + 1);
}
void solve(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int fh1 = a, fh2 = b;
    int sh1 = c - a, sh2 = d - b;

    bool possible = ok(fh1, fh2) && ok(sh1, sh2);
    cout << (possible ? "YES\n" : "NO\n");
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