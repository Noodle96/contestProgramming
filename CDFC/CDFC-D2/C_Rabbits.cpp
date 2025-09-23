/*
==========================================================
|  Archivo       : C_Rabbits.cpp
|  Autor         : Russell
|  Fecha         : 2025-09-20 11:09
|--------------------------------------------------------
|  Tópicos utilizados:
|  - strings
|  - div2
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
    int n; cin >> n;
    string s; cin >> s;

    bool ans = true;
    for (int i = 0; i < n; ) {
        if (s[i] != '1') {
            i++;
            continue;
        }
        int j = i, kzeros = 0;
        while (j + 2 < n && s[j+1] == '0' && s[j+2] == '1') {
            kzeros++;
            j += 2;
        }
        bool left  = (i == 0 || s[i-1] == '1');
        bool right = (j + 1 == n || s[j+1] == '1');

        if (left && right && (kzeros & 1)){
            ans = false;
            break;
        }
        i = (j == i ? i + 1 : j + 1);
    }

    cout << (ans ? "YES" : "NO") << endl;
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