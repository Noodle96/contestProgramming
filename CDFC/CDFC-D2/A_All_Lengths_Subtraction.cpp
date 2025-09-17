/*
==========================================================
|  Archivo       : A_All_Lengths_Subtraction.cpp
|  Autor         : Russell
|  Fecha         : 2025-09-17 09:49
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

vector<int> a;
int n;
int findNumber(int number){
    for(int i=0; i<n; i++){
        if(a[i] == number) return i;
    }
    return -1;
}

void solve(){
    cin >> n;
    a.resize(n);
    for(int i=0; i<n; i++) cin >> a[i];
    int target = n;
    for(int k = 1 ; k <= n; k++){
        int pos = findNumber(target);
        // cout << "pos: " << pos << endl;
        int e = 0;
        while(pos < n){
            if(a[pos] == target){
                a[pos]--;
                e++;
                pos++;
            }
            else break;
        }
        target--;
        if(e != k){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;

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