/*
==========================================================
|  Archivo       : Adaptation.cpp
|  Autor         : Russell
|  Fecha         : 2025-10-11
|--------------------------------------------------------
|  Tópicos utilizados:
|  - rpc
|  - implementation
|  - binary search
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


ll floordiv(ll a, ll b) {
    if (a >= 0) return a / b;
    return - ( (-a + b - 1) / b );
}
ll ceildiv(ll a, ll b) {
    // ceil(a/b) = -floor((-a)/b)
    if (a >= 0) return (a + b - 1) / b;
    return - ( (-a) / b );
}

void solve(){
    int n; int l, h;
    cin >> n >> l >> h;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int> kmin(n), kmax(n);
    for (int i = 0; i < n; ++i) {
        ll kmn = ceildiv((ll)l - a[i], 12LL);
        ll kmx = floordiv((ll)h - a[i], 12LL);
        kmin[i] = (int)kmn;
        kmax[i] = (int)kmx;
    }

    vector<int> reach(n, -1);
    deque<int> dqMaxKmin;
    deque<int> dqMinKmax;
    auto valid = [&]() -> bool {
        if (dqMaxKmin.empty()) return true;
        int maxKmin = kmin[dqMaxKmin.front()];
        int minKmax = kmax[dqMinKmax.front()];
        return maxKmin <= minKmax;
    };

    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j < n) {
            while (!dqMaxKmin.empty() && kmin[dqMaxKmin.back()] <= kmin[j]) dqMaxKmin.pop_back();
            dqMaxKmin.push_back(j);
            while (!dqMinKmax.empty() && kmax[dqMinKmax.back()] >= kmax[j]) dqMinKmax.pop_back();
            dqMinKmax.push_back(j);

            if (valid()) {
                ++j;
            } else {
                if (!dqMaxKmin.empty() && dqMaxKmin.back() == j) dqMaxKmin.pop_back();
                if (!dqMinKmax.empty() && dqMinKmax.back() == j) dqMinKmax.pop_back();
                break;
            }
        }
        reach[i] = j - 1;

        if (!dqMaxKmin.empty() && dqMaxKmin.front() == i) dqMaxKmin.pop_front();
        if (!dqMinKmax.empty() && dqMinKmax.front() == i) dqMinKmax.pop_front();
    }

    auto feasible = [&](int L) -> bool {
        int N = (int)reach.size();
        vector<int> diff(N + 3, 0);
        diff[0] += 1;
        diff[1] -= 1;

        int cur = 0;
        for (int i = 0; i <= N; ++i) {
            cur += diff[i];
            if (i == N) return cur > 0;
            if (cur <= 0) continue;

            if (reach[i] >= i + L - 1) {
                int lo = i + L;
                int hi = reach[i] + 1;
                if (lo <= N) {
                    diff[lo] += 1;
                    diff[hi + 1] -= 1;
                }
            }
        }
        return false;
    };

    int lo = 1, hi = n, ans = 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (feasible(mid)) {
            ans = mid;
            lo = mid + 1;
        } else hi = mid - 1;
    }

    cout << ans << endl;
}
void solve2(){
    cout << floor(-18/4) << " " << ceil(-18/4) << "\n";
    cout << floordiv(-18,4) << " " << ceildiv(-18,4) << "\n";
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
        solve2();
    }
    return 0;
}