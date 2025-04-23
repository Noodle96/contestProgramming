/*
==========================================================
|  Archivo       : G_Chimpanzini_Bananini.cpp
|  Autor         : Russell
|  Fecha         : 2025-04-23 15:41
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Data Structure: Queue
|  - Implementation
|  - Math
   - *1700
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
    int q; cin>>q;
    deque<ll> dNormal, dReverse;
    ll total = 0, n = 0;
    ll ansNormal = 0, ansReverse = 0;
    while(q--){
        int s; cin>>s;
        if(s == 1){
            int last = dNormal.back();
            dNormal.pop_back();
            dNormal.push_front(last);

            total -= last;
            ansNormal -= (last*n);
            ansNormal +=total;
            ansNormal += last*1;
            total += last;

            int first = dReverse.front();
            dReverse.pop_front();
            dReverse.push_back(first);

            total -= first;
            ansReverse -= first;
            ansReverse -= total;
            ansReverse += first*n;
            total += first;
        }else if(s == 2){
            swap(dNormal, dReverse);
            swap(ansNormal, ansReverse);
        }else{
            // s == 3
            n++;
            ll k; cin>>k;
            dNormal.push_back(k);
            dReverse.push_front(k);
            
            ansNormal += n*k;
            ansReverse += total;
            ansReverse += k*1;
            total += k;
        }
        cout << ansNormal << endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t; cin>>t;
    while(t--) solve();
    return 0;
}


