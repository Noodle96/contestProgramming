/*
==========================================================
|  Archivo       : A_Painting_With_Two_Colors.cpp
|  Autor         : Russell
|  Fecha         : 2025-08-26 09:44
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Div 2
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
    long long n, a, b;
    cin >> n >> a >> b;
    bool ok = ( (n % 2) == (b % 2) ) && ( a <= b || (n % 2) == (a % 2) );
    cout << (ok ? "YES" : "NO") << '\n';
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