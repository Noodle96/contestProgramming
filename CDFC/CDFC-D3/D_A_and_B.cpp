/*
==========================================================
|  Archivo       : D_A_and_B.cpp
|  Autor         : Russell
|  Fecha         : 2025-09-25 11:27
|--------------------------------------------------------
|  Tópicos utilizados:
|  - implementation
|  - div3
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

ll f(const string& s, char ch) {
    vector<int> pos;
    for (int i = 0; i < (int)s.size(); ++i)
        if (s[i] == ch) pos.push_back(i);
        
    int m = (int)pos.size();
    if (m <= 1) return 0LL;

    vector<ll> q(m);
    for (int i = 0; i < m; ++i) q[i] = (ll)pos[i] - i;
    // sort(q.begin(), q.end());
    ll med = q[m/2];

    ll ans = 0;
    for (int i = 0; i < m; ++i) ans += llabs(q[i] - med);
    return ans;
}

void solve(){
    int n; string s;
    cin >> n >> s;
    ll ansA = f(s, 'a');
    ll ansB = f(s, 'b');
    cout << min(ansA, ansB) << endl;
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