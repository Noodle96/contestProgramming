/*
==========================================================
|  Archivo       : binarySearch.cpp
|  Autor         : Russell
|  Fecha         : 2025-05-03 16:57
|--------------------------------------------------------
|  Tópicos utilizados:
|  - BinarySearch
|  - LowerBound
|  - UpperBound
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

int my_upperBound(vector<int> &vec, int x){
    int l = 0, r = vec.size();
    while(l < r){
        int m = l + (r - l) / 2;
        if(vec[m] <= x) l = m + 1;
        else r = m;
    }
    return l;
}
int my_lowerBound(vector<int> &vec, int x){
    int l = 0, r = vec.size();
    while(l < r){
        int m = l + (r - l) / 2;
        if(vec[m] < x) l = m + 1;
        else r = m;
    }
    return l;
}
void solve(){
    vector<int> h = {10, 20, 30, 30 ,40 , 50};
    int k = 30;
    cout << "Upper Bound: " << my_upperBound(h, k) << endl;
    cout << "Lower Bound: " << my_lowerBound(h, k) << endl;
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