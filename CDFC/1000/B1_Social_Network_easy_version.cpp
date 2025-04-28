/*
==========================================================
|  Archivo       : B2_Social_Network_hard_version.cpp
|  Autor         : Russell
|  Fecha         : 2025-04-28 16:30
|--------------------------------------------------------
|  Tópicos utilizados:
|  - DataStructures: Set, deque
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
int val;
void solve(){
    int n,k;
    cin>>n>>k;
    set<int> s;
    deque<int> dq;
    while(n--){
        cin>>val;
        if(dq.size() < k){
            auto it_find = s.find(val);
            if(it_find != s.end()){
                //nothing to do
            }else{
                dq.push_front(val);
                s.insert(val);
            }
        }else{
            auto it_find = s.find(val);
            if(it_find != s.end()){
                //nothing to do
            }else{
                int last = dq.back();
                dq.pop_back();
                s.erase(last);
                dq.push_front(val);
                s.insert(val);
            }
        }
    }
    cout << dq.size() << endl;
    for(int e = 0 ; e < dq.size(); e++){
        if(e == dq.size()-1) cout << dq[e];
        else cout << dq[e] << " ";
    }cout << endl;
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