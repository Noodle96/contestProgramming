/*
==========================================================
|  Archivo       : Welcome.cpp
|  Autor         : Russell
|  Fecha         : 2025-04-26 18:53
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
/*
welcome
    ..we... 
..are..
    ..open.
    .free..
    .coffee
..for..
    .icpc..
*/
string dots;
int rowUnEqual = 1;
void solve(){
    int r,c;
    cin>>r>>c;
    vector<string> words(r);
    for(int e = 0 ; e < r; e++) cin>>words[e];
    for(int e = 0 ; e < r; e++){
        auto lenWord = words[e].length();
        auto spaces = c - lenWord; 
        if(spaces%2 == 0){
            spaces /= 2;
            dots.assign(spaces,'.');
            words[e] = dots + words[e] + dots;
        }else{
            spaces /= 2;
            dots.assign(spaces,'.');
            if(rowUnEqual%2 == 1) words[e] = dots + words[e] + dots + '.';
            else words[e] = dots + '.' + words[e] + dots;
            rowUnEqual++;
        }
    }
    for(auto word_i: words){
        cout << word_i << endl;
    }
}
void solve2(){
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