/*
==========================================================
|  Archivo       : H_Honey_Cake.cpp
|  Autor         : Russell
|  Fecha         : 2026-01-23 17:11
|--------------------------------------------------------
|  Tópicos utilizados:
|  - training
|  - math
|  - *1200
==========================================================
*/

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;
using ll = long long;
using i64 = int64_t;
using i32 = int32_t;
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

const int INF = 1e9;

ll gcd(ll a, ll b) {
    if (a % b == 0) return b;
    else return gcd(b, a % b);
}

ll floordiv(ll a, ll b) {
    if (a >= 0) return a / b;
    return - ( (-a + b - 1) / b );
}

ll ceildiv(ll a, ll b) {
    // ceil(a/b) = -floor((-a)/b)
    if (a >= 0) return (a + b - 1) / b;
    return - ( (-a) / b );
}

int bitlen_unsigned(unsigned long long n) {
    // __builtin_clzll: Cuenta los ceros a la izquierda
    return (n == 0) ? 1 : 64 - __builtin_clzll(n);
}

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

void solve() {
    ll w,h,d;
    cin >> w >> h >> d;
    ll n;
    cin >> n;

    if(n == 1){
        cout << w << " " << h << " " << d << "\n";
        return;
    }

    multiset<ll> factoresW, factoresH, factoresD, factoresDen;
    factoresW.insert(1);
    factoresH.insert(1);
    factoresD.insert(1);

    auto computeFactors = [](ll x, multiset<ll>& factores) {
        for (ll i = 2; i * i <= x; i++) {
            while (x % i == 0) {
                factores.insert(i);
                x /= i;
            }
        }
        if (x > 1) {
            factores.insert(x);
        }
    };

    computeFactors(w, factoresW);
    computeFactors(h, factoresH);
    computeFactors(d, factoresD);
    computeFactors(n, factoresDen);

    for(auto f: factoresDen){
        auto find_f = factoresW.find(f);
        if(find_f != factoresW.end()){
            factoresW.erase(find_f);
            continue;
        }
        find_f = factoresH.find(f);
        if(find_f != factoresH.end()){
            factoresH.erase(find_f);
            continue;
        }
        find_f = factoresD.find(f);
        if(find_f != factoresD.end()){
            factoresD.erase(find_f);
            continue;
        }
        cout << -1 << "\n";
        return; 
    }

    auto computeProduct = [](const multiset<ll>& factores) {
        ll result = 1;
        for (ll f : factores) {
            result *= f;
        }
        return result;
    };
    ll newW = computeProduct(factoresW);
    ll newH = computeProduct(factoresH);
    ll newD = computeProduct(factoresD);

    cout << w/newW - 1 << " " << h/newH - 1<< " " << d/newD -1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;
    // cin >> t;
    t = 1;
    while (t--) {
        solve();
    }
    return 0;
}