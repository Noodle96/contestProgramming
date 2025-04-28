/*
==========================================================
|  Archivo       : B_Build_a_Contest.cpp
|  Autor         : Russell
|  Fecha         : 2025-04-28 13:43
|--------------------------------------------------------
|  Tópicos utilizados:
|  - DataStructures: Set, Unordered_map
|  - *1300
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
int temp;
void solve(){
    int n, m; cin>>n>>m;
    set<int> s;
    unordered_map<int, int> um;
    while(m--){
        cin>>temp;
        s.insert(temp);
        um[temp]++;
        if(s.size() == n){
            s.clear();
            cout << "1";
            for(auto &[key,value]: um){
                value--;
                if(value > 0){
                    s.insert(key);
                }
            }
        }else{
            cout << "0";
        }
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
    solve();
    return 0;
}