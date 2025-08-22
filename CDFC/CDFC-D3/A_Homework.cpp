/*
==========================================================
|  Archivo       : A_Homework.cpp
|  Autor         : Russell
|  Fecha         : 2025-08-21 09:43
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Div 3
|  - Implementation
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
    int len_a, len_b;
    deque<char> d_a, d_b;
    string a,b;
    cin >> len_a >> a;
    cin >> len_b >> b;
    for(int e = 0; e < len_a ; e++) d_a.pb(a[e]);
    for(int e = 0; e < len_b ; e++) d_b.pb(b[e]);


    string distribucion;
    cin >> distribucion;

    for(auto dis: distribucion){
        if(dis == 'V'){
            d_a.push_front(d_b.front());
            d_b.pop_front();
        }else{ // D
            d_a.push_back(d_b.front());
            d_b.pop_front();
        }
    }
    for(auto it = d_a.begin(); it != d_a.end() ; it++){
        cout << *it;
    }cout << endl;

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