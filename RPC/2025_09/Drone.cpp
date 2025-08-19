/*
==========================================================
|  Archivo       : Drone.cpp
|  Autor         : Russell
|  Fecha         : 2025-08-16 16:09
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Tema 1: Programación Lineal
|  - Tema 2: Simplex(no implementado aun)
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
    int q; cin>>q;
    cout.setf(std::ios::fixed); cout<<setprecision(10);
    for(int i=0;i<q;i++){
        double p,r,y; cin>>p>>r>>y;
        double M = max({fabs(p)/2.0, fabs(r)/2.0, (fabs(y)+fabs(p)+fabs(r))/4.0});
        double L1 = -2.0*M + fabs(r);
        double R1 =  2.0*M - fabs(r);
        double L2 = y - 2.0*M + fabs(p);
        double R2 = y + 2.0*M - fabs(p);
        double L = max(L1, L2);
        double R = min(R1, R2);
        double a;
        if (L > R) a = 0.5*(L+R); else a = 0.5*(L+R);
        double n = (a + r)/2.0;
        double s = (a - r)/2.0;
        double e = ((y - a) + p)/2.0;
        double w = ((y - a) - p)/2.0;
        cout<<n<<" "<<e<<" "<<s<<" "<<w<<"\n";
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