/*
==========================================================
|  Archivo       : 12578_10_6_2.cpp
|  Autor         : Russell
|  Fecha         : 2025-08-20 16:20
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
const double PI = acos(-1.0);

ll gcd(ll a,ll b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

void solve(){
    double L;
    cin >> L;
    double w = 0.6*L;
    double r = 0.2*L;

    double areaTotal = L * w; // area of the rectangle
    double areaCircle = PI * r * r; // area of the circle
    double areaRemains = areaTotal - areaCircle; // area of the remaining part
    cout << fixed << setprecision(2);
    cout << areaCircle << " " << areaRemains << endl;
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