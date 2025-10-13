/*
==========================================================
|  Archivo       : Item.cpp
|  Autor         : Russell
|  Fecha         : 2025-10-11
|--------------------------------------------------------
|  Tópicos utilizados:
|  - rpc
|  - implementation
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
    int n, m, s, p, q;
    cin >> n >> m >> s >> p >> q;

    vector<char> pre(n + 1, 0), want(n + 1, 0);
    for (int i = 0; i < p; ++i) {
        int x; cin >> x;
        pre[x] = 1;
    }
    for (int i = 0; i < q; ++i) {
        int x; cin >> x;
        want[x] = 1;
    }

    int P = (n + m - 1) / m;

    ll per_page_cost = 0;
    int first_needed = INT_MAX, last_needed = INT_MIN;

    for (int page = 1; page <= P; ++page) {
        int L = (page - 1) * m + 1;
        int R = min(page * m, n);
        int t = R - L + 1;

        int cntS = 0, cntT = 0, xorDiff = 0;
        for (int i = L; i <= R; ++i) {
            cntS += pre[i];
            cntT += want[i];
            xorDiff += (pre[i] ^ want[i]);
        }

        int optionFlipIndividually = xorDiff;
        int optionSelectAll = 1 + (t - cntT);
        int optionDeselectAll = 1 + cntT;

        int best = min(optionFlipIndividually, min(optionSelectAll, optionDeselectAll));

        if (best > 0) {
            per_page_cost += best;
            first_needed = min(first_needed, page);
            last_needed  = max(last_needed, page);
        }
    }

    ll nav = 0;
    if (first_needed == INT_MAX) {
        nav = 0;
    } else {
        if (s < first_needed)      nav = last_needed - s;
        else if (s > last_needed)  nav = s - first_needed;
        else {
            nav = (last_needed - first_needed) + min(s - first_needed, last_needed - s);
        }
    }

    cout << (per_page_cost + nav) << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;
    //cin >> t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}