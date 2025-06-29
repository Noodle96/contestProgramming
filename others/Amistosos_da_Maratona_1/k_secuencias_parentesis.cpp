/*
==========================================================
|  Archivo       : k_secuencias_parentesis.cpp
|  Autor         : Russell
|  Fecha         : 2025-06-28 13:32
|--------------------------------------------------------
|  Tópicos utilizados:
|  - implementacion
|  - stack
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
    int n,k; cin>>n>>k;
    string s; cin>>s;
    stack<char> pila;

    int open = 0, close = 0;
    string ans = "";
    for (char c : s) {
        if (c == '(') {
            if (open < k / 2) {
                ans += '(';
                open++;
            }
        } else {
            if (close < open) {
                ans += ')';
                close++;
            }
        }
        if (ans.size() == k) break;
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
    solve();
    return 0;
}