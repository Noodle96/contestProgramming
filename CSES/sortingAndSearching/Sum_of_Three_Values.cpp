/*
==========================================================
|  Archivo       : Sum_of_Three_Values.cpp
|  Autor         : Russell
|  Fecha         : 2025-08-14 11:51
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Brute force
|  - Binary Search
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
    int n; ll x;
    cin >> n >> x;
    vector<pair<ll, int>> a(n);
    for(int e = 0 ; e < n; e++){
        cin>>a[e].first;
        a[e].second = e;
    }
    sort(all(a));

    for(int e = 0 ; e < n-1; e++){
        // cout << "e: " << e;
        for(int j = e+1; j < n ; j++){
            // cout << " j: " << j << endl;
            ll targat = x - a[e].first - a[j].first;
            if(targat < 0) continue;
            int l = j + 1, r = n - 1;
            if (l > n-1) continue;
            // cout << "begin while" << endl;
            while(l <= r){
                int m = (l + r) / 2;
                if(a[m].first < targat) l = m + 1;
                else r = m - 1;

                if(a[m].first == targat ){
                    cout << a[e].second + 1 << " " << a[j].second + 1 << " " << a[m].second + 1 << "\n";
                    return;
                }
            }
            // cout << "end while" << endl;
        }
    }
    cout << "IMPOSSIBLE\n";
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