/*
==========================================================
|  Archivo       : B_Maximum_Cost_Permutation.cpp
|  Autor         : Russell
|  Fecha         : 2025-09-15
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Implementation
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
    int n; cin >> n;
    vector<int> a(n);
    int cntZeros = 0;
    unordered_map<int,int> freq;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == 0) cntZeros++;
        freq[a[i]]++;
    }

    int l = 0;
    while (l < n){
        if(a[l] == l+1) ++l;
        else{
            if(a[l] == 0 && cntZeros == 1 && freq.count(l+1) == 0){
                freq[l+1]++;
                ++l;
            }else break;
        }
    }

    int r = n - 1;
    while (r >= l){
        if(a[r] == r+1) --r;
        else if(a[r] == 0 && cntZeros == 1 && freq.count(r+1) == 0){
            freq[r+1]++;
            --r;
        }else break;
    }

    int ans = (l > r) ? 0 : (r - l + 1);
    cout << ans << endl;
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