/*
==========================================================
|  Archivo       : D_Replace_with_Occurrences.cpp
|  Autor         : Russell
|  Fecha         : 2025-09-07 10:25
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Data Structures
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
    vector<int> b(n);
    for (int i = 0; i < n; ++i) cin >> b[i];

    vector<vector<int>> buckets(n + 1);
    for (int i = 0; i < n; ++i) {
        buckets[b[i]].push_back(i);
    }

    bool ok = true;
    for (int k = 1; k <= n; ++k) {
        if (!buckets[k].empty() && (int)buckets[k].size() % k != 0) {
            ok = false; break;
        }
    }
    if (!ok) {
        cout << -1 << endl;
        return;
    }

    vector<int> a(n, 0);
    int label = 1;
    for (int k = 1; k <= n; ++k) {
        auto &vec = buckets[k];
        for (int i = 0; i < (int)vec.size(); i += k) {
            for (int j = 0; j < k; ++j) {
                a[vec[i + j]] = label;
            }
            ++label;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << a[i];
    }
    cout << endl;
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