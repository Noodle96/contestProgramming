/*
==========================================================
|  Archivo       : F_Longest_Strike.cpp
|  Autor         : Russell
|  Fecha         : 2026-02-08 21:42
|--------------------------------------------------------
|  Tópicos utilizados:
|  - sorting
|  - training
|  - greedy
|  - data structures
|  - Lev 2
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
    int n,k; cin >> n >> k;
    // cout << "Case " << n << " " << k << endl;
    map<int,int> freq;
    vector<int> vec;
    for(int i = 0 ;i < n ; i++){
        int a; cin >> a;
        freq[a]++;
        vec.pb(a);
    }
    sort(all(vec));
    auto it = unique(all(vec));
    vec.erase(it, vec.end());


    int n_ = vec.size();
    int i = 0;
    int l = -1, r = -1, current = -1;
    


    auto findNextValid = [&]() -> void {
        // Encontrar el el valor que cumple vec[i] >= k
        while(i < n_ && freq[vec[i]] < k) i++;
        if(i < n_){
            l = vec[i];
            r = vec[i];
            current = vec[i];
            i++;
        }
    };

    int maxAns = -1;
    int ansL = -1, ansR = -1;

    auto add = [&](int l, int r) -> void {
        if(r - l > maxAns){
            maxAns = r - l;
            ansL = l;
            ansR = r;
        }
    };

    while(i < n_){
        findNextValid();
        while(i < n_){
            if(freq[vec[i]] >= k){
                if(vec[i] == current + 1){
                    r = vec[i];
                    current = vec[i];
                    i++;
                }else{
                    add(l,r);
                    findNextValid();
                }
            }else{
                add(l,r);
                findNextValid();

            }
        }
    }
    if(l != -1 && r != -1 ) add(l,r);
    if(maxAns == -1){
        cout << -1 << endl;
    }else{
        cout << ansL << " " << ansR << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifdef DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    // t = 1;
    while (t--) {
        solve();
    }
    return 0;
}