/*
==========================================================
|  Archivo       : B_Not_Quite_Latin_Square.cpp
|  Autor         : Russell
|  Fecha         : 2025-04-17 15:52
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Bitmask
|  - Brute force
|  - Implementación
|  - *800
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
    string line;
    int number;
    vector<int> bitsOfNumbers(2,0);
    for(int e = 0;e < 3 ; e++){
        cin>>line;
        for(auto ch: line){
            if(ch == '?') continue;
            if(ch == 'A') number = 1;
            if(ch == 'B') number = 2;
            if(ch == 'C') number = 3;
            for(int j = 0; j < 2; j++){
                if( (number >> j) & 1 ) bitsOfNumbers[j]++;
            }
        }
    }
    int ans = 0;
    for(int e = 0 ;e < 2 ; e++){
        int restante = 6 - bitsOfNumbers[e];
        ans += (restante << e);
    }
    cout << (ans == 1 ? 'A' : (ans == 2 ? 'B' : 'C')) << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t; cin>>t;
    while(t--) solve();
    return 0;
}