/*
==========================================================
|  Archivo       : B_Like_the_Bitset.cpp
|  Autor         : Russell
|  Fecha         : 2025-08-28
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Div 2
|  - Constructive algorithms
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
    int n, k; string s;
    cin >> n >> k >> s;

    //1.- Chequear si hay k unos consecutivos
    int consec = 0; 
    bool bad = false;
    for (char c : s) {
        if (c == '1') consec++;
        else consec = 0;
        if (consec >= k) { bad = true; break; }
    }
    if (bad) {
        cout << "NO" << endl;
        return;
    }

    // 2) Construir la permutación
    cout << "YES\n";
    vector<int> p(n);
    int ones = count(s.begin(), s.end(), '1');
    int small = 1;           // para s[i]=1
    int big = ones + 1;      // para s[i]=0

    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') p[i] = small++;
        else p[i] = big++;
    }

    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << p[i];
    }
    cout << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t; cin >> t;
    while(t-- ) solve();
    return 0;
}