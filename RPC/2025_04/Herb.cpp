/*
==========================================================
|  Archivo       : Herb.cpp
|  Autor         : Russell
|  Fecha         : 2025-04-26 13:23
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Tema 1
|  - Tema 2
|  - Tema 3
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
    int g,r;
    cin>>g>>r;
    int g_r;
    int total = 0;
    if(g >= r){
        g_r = r;
        g -= g_r;
        total += g_r*10;
        // cout << "total: " << total << " g:  " << g<< endl;

        int enteroG = g/3;
        g = g%3;
        total += enteroG*10;
        int restoG = g%3;

        // cout << "total: " << total << " g:  " << g<< endl;

        int enteroG2 = restoG/2;
        total += enteroG2*3;
        enteroG2 = restoG%2;

        if (enteroG2 == 1) total += 1;

        // cout << "total: " << total << " g:  " << g<< endl;

        cout << total << endl;
    }else{
        int g_r = g;
        int total = g_r*10;
        g -= g_r;
        // cout << "total: " << total << " g:  " << g<< endl;
        cout << total << endl;
    }
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