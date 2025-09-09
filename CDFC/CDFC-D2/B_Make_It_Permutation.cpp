/*
==========================================================
|  Archivo       : B_Make_It_Permutation.cpp
|  Autor         : Russell
|  Fecha         : 2025-06-12 10:43
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
    int n;
        cin >> n;
        vector<tuple<int,int,int>> ops;
        for (int i = 2; i <= n; ++i) {
            int k = i - 1;
            ops.emplace_back(i, 1, k);
            ops.emplace_back(i, k+1, n);
            ops.emplace_back(i, 1, n);
        }
        cout << ops.size() << '\n';
        for (auto &op : ops) {
            int i, l, r;
            tie(i, l, r) = op;
            cout << i << ' ' << l << ' ' << r << '\n';
        }
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