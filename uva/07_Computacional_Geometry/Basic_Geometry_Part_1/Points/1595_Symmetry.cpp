/*
==========================================================
|  Archivo       : 1595_Symmetry.cpp
|  Autor         : Russell
|  Fecha         : 2025-08-19 12:02
|--------------------------------------------------------
|  Tópicos utilizados:
|  - Geometry Computacional
|  - Points
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
const double EPS = 1e-9;

ll gcd(ll a,ll b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
struct Point_i{
    int x, y;
    Point_i() : x(0), y(0) {}
    Point_i(int x_, int y_) : x(x_), y(y_) {}
    bool operator < (Point_i other) const {
        if (x != other.x)
            return x < other.x;
        return y < other.y;
    }
    bool operator == (Point_i other) const {
        return (x == other.x) && (y == other.y);
    }
};

void solve(){
    map<int, set<int>> points;
    int n; cin >> n;
    while(n--){
        int x,y; cin >> x >> y;
        points[y].insert(x);
    }
    // cout << "print points" << endl;
    // for(auto &[k, v]: points){
    //     cout << "y = " << k << ": ";
    //     for(int x : v){
    //             cout << x << " ";
    //     }
    //     cout << endl;
    // }
    
    set<double> ans_middleLine;
    // cout << "\nprocessing points" << endl;
    for(auto &[y, xs] : points){
        // cout << "y = " << y << ": " << endl;
        int len = xs.size();
        len /=2;
        for(int e = 0 ; e < len; e++){
            auto first = xs.begin();
            auto last = prev(xs.end());
            auto middle = (*last - *first)/2.0;
            ans_middleLine.insert(*first + middle);
            xs.erase(first);
            xs.erase(last);
        }
        if(xs.size() == 1) ans_middleLine.insert(*xs.begin());
    }
    if(ans_middleLine.size() == 1) cout << "YES"<< endl;
    else cout << "NO" << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t; cin >> t;
    while(t--) solve();
    return 0;
}