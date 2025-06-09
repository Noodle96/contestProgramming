/*
==========================================================
|  Archivo       : Apivotal.cpp
|  Autor         : Russell
|  Fecha         : 2025-06-07 17:12
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
    vector<int> A(n);
    for (int &x : A) cin >> x;

    // 1) prefixMax[i] = max(A[0..i])
    vector<int> prefixMax(n);
    prefixMax[0] = A[0];
    for (int i = 1; i < n; ++i)
        prefixMax[i] = max(prefixMax[i-1], A[i]);

    // 2) suffixMin[i] = min(A[i..n-1])
    vector<int> suffixMin(n);
    suffixMin[n-1] = A[n-1];
    for (int i = n-2; i >= 0; --i)
        suffixMin[i] = min(suffixMin[i+1], A[i]);

    // 3) contar todos los pivotes y guardar sólo los primeros 100
    int total = 0;
    vector<int> first100;
    first100.reserve(100);

    for (int i = 0; i < n; ++i) {
        bool okLeft  = (prefixMax[i] == A[i]);
        bool okRight = (i == n-1) 
                       ? true 
                       : (suffixMin[i+1] > A[i]);

        if (okLeft && okRight) {
            ++total;
            if ((int)first100.size() < 100)
                first100.push_back(A[i]);
        }
    }

    // 4) salida: total m, luego hasta 100 pivotes
    cout << total;
    if (total > 0) {
        cout << ' ';
        for (int i = 0; i < (int)first100.size(); ++i) {
            if (i) cout << ' ';
            cout << first100[i];
        }
    }
    cout << "\n";
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