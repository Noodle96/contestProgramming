/*
==========================================================
|  Archivo       : List.cpp
|  Autor         : Russell
|  Fecha         : 2025-05-17 16:35
|--------------------------------------------------------
|  Tópicos utilizados:
|  - DataStructures: Multiset
|  - Two Pointers
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

struct MedianDS {
    multiset<int> lo, hi;
    int mid;

    MedianDS() {
        // empieza vacío
        mid = 0;
    }

    void rebalance() {
        // garantizar |lo| == |hi| o |lo| == |hi| + 1
        if (lo.size() > hi.size() + 1) {
            // mover el mayor de lo a hi
            auto it = prev(lo.end());
            hi.insert(*it);
            lo.erase(it);
        }
        else if (hi.size() > lo.size()) {
            // mover el menor de hi a lo
            auto it = hi.begin();
            lo.insert(*it);
            hi.erase(it);
        }
        if(lo.size() == hi.size() && lo.size() > 0){
            mid = (*prev(lo.end()) + *hi.begin() )/2;
        }else{
            // actualizar mid
            if(lo.size() == 0) mid = -1;
            else mid = *prev(lo.end());
        }
        
    }

    void insert(int x) {
        if (lo.empty() || x <= mid) lo.insert(x);
        else hi.insert(x);
        rebalance();
    }

    void erase_one(int x) {
        auto it = lo.find(x);
        if (it != lo.end()) lo.erase(it);
        else {
            it = hi.find(x);
            if (it != hi.end()) hi.erase(it);
            else return; // no estaba
        }
        rebalance();
    }

    int get_median() const {
        if (lo.empty()) return -1;
        return mid;
    }
};

void solve(){
    MedianDS ds;
    int q; 
    cin >> q;
    while (q--) {
        int type, val;
        cin >> type;
        if (type == 1) {
            cin >> val;
            ds.insert(val);
        }
        else if (type == 2) {
            cin >> val;
            ds.erase_one(val);
        }
        else if (type == 3) {
            if(ds.get_median() == -1){
                cout << "Empty!\n";
            }else{
                cout << ds.get_median() << "\n";
            }
        }
    }
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