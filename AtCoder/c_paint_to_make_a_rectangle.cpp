#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define msg(str,str2) cout << str << str2<< endl
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

#define pb push_back
#define mp make_pair

ll gcd(ll a,ll b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

void solve(){
    int r,c; cin>>r>>c;
    vector<vector<char>> grid(r,vector<char>(c));
    for(int e = 0 ;e < r ; e++){
        for(int j = 0 ; j < c; j++){
            cin>>grid[e][j];
        }
    }
    // cout << "print grid" << endl;
    // for(int e = 0 ;e < r ; e++){
    //     for(int j = 0 ; j < c; j++){
    //         cout << grid[e][j];
    //     } cout << endl;
    // }cout << endl;

    set<int> s_row,s_col;
    for(int e = 0 ; e < r; e++){
        for(int j = 0 ; j < c;j++){
            if(grid[e][j] == '#'){
                s_col.insert(j);
                s_row.insert(e);
            }
        }
    }
    int a = *s_col.begin();
    int b = *s_col.rbegin();
    int cp = *s_row.begin();
    int d = *s_row.rbegin();
    bool ans = true;
    // cout << a << " " << b << " " << cp << " " << d << endl;
    for(int e = cp ; e <= d ; e++){
        for(int j = a ; j <= b ; j++){
            ans &= (grid[e][j] == '#' || grid[e][j] == '?');
        }
    }
    cout << (ans ? "Yes" : "No") << endl;
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