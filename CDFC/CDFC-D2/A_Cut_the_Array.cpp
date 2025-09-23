/*
==========================================================
|  Archivo       : A_Cut_the_Array.cpp
|  Autor         : Russell
|  Fecha         : 2025-09-15 09:47
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
int n;
vector<int> a;

bool func(int l, int r){
    int s1 = 0,s2 = 0,s3 = 0;
    for(int e = 0 ;e <= l ; e++) s1 += a[e];
    s1 %= 3;
    for(int e = l+1 ; e <= r ; e++) s2 += a[e];
    s2 %= 3;
    for(int e = r+1 ; e < n ; e++) s3 += a[e];
    s3 %= 3;
    // cout << s1 << " " << s2 << " " << s3 << endl;
    if(s1 == s2 && s2 == s3) return true;
    if(s1 != s2 && s2 != s3 && s1 != s3) return true;
    return false;
}

void solve(){
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int l = 0 ;l < n ; l++){
        for(int r = l+1 ; r < n; r++){
            if(func(l,r)){
                cout << l+1 << " " << r+1 << endl;
                return;
            }
        }
    }
    cout << 0 << " " << 0 << endl;
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