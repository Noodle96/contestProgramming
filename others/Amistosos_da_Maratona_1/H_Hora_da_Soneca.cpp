/*
==========================================================
|  Archivo       : H_Hora_da_Soneca.cpp
|  Autor         : Russell
|  Fecha         : 2025-06-28 13:58
|--------------------------------------------------------
|  Tópicos utilizados:
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
    int n;
    cin >> n;
    vector<int> v(n);
    for(int e = 0 ;e < n ; e++){
        cin >> v[e];
    }
    int maxSize = 0;
    int intervalSize = 0;
    for(int e = 0 ;e < n ; e++){
        if(v[e] == 1){
            intervalSize++;
            maxSize = max(maxSize, intervalSize);
        }else{
            intervalSize = 0;
        }
    }
    int sizeFirst = 0, sizeLast = 0;
    if(v[0] == 1){
        for(int e = 0 ; ; e++){
            if(v[e] == 1){
                sizeFirst++;
            }else{
                break;
            }
        }
    }
    if(v[n-1] == 1){
        for(int e = n-1 ; e >= 0 ; e--){
            if(v[e] == 1){
                sizeLast++;
            }else{
                break;
            }
        }
    }
    if(sizeFirst > 0 && sizeLast > 0){
        maxSize = max(maxSize, sizeFirst + sizeLast);
    }
    cout << maxSize << endl;

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