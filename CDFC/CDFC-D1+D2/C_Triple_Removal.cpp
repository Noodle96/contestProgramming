/*
==========================================================
|  Archivo       : C_Triple_Removal.cpp
|  Autor         : Russell
|  Fecha         : 2025-10-03 17:10
|--------------------------------------------------------
|  Tópicos utilizados:
|  - div1 + div2
|  - greedy
|  - math
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
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for(auto &x: a) cin >> x;

    // tebemos qe contar la cantidad de zeros y unos, oero como son solo 0 y 1,
    // funciona un prefix_sum
    vector<int> prefix_sum(n+1);
    prefix_sum[0] = 0;
    for(int i = 1; i <=n; i++){
        prefix_sum[i] = prefix_sum[i-1] + a[i-1];
    }
    // ademas, tenemos que ver si en un intervalo [l,r] existe algun adyacente
    // que sean iguales.
    vector<int> prefix_same(n);
    prefix_same[0] = 0;
    for(int i =  1; i < n; i++){
        if(a[i] == a[i-1])  prefix_same[i] = i;
        else prefix_same[i] = prefix_same[i-1];
    }
    while(q--){
        int l, r; cin >> l >> r;
        int ones = prefix_sum[r] - prefix_sum[l-1];
        int len = r - l + 1;
        if(ones % 3 !=0 || len%3 != 0){
            cout << -1 << endl;
            continue;
        }
        // tenemos que verificar si en dicho intervalo [l,r] existe algun adyacente 
        // que sean iguales
        if(prefix_same[r-1] > l){
            cout << len/3 << endl;
        }else{
            cout << len/3 + 1 << endl;
        }
    }
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