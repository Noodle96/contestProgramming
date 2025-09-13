/*
==========================================================
|  Archivo       : 455_Periodic_Strings.cpp
|  Autor         : Russell
|  Fecha         : 2025-09-13 13:58
|--------------------------------------------------------
|  Tópicos utilizados:
|  - String processing
|  - String matching
|  - Periodic strings
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

vector<int> divisores(int n){
    vector<int> divs;
    for(int i = 1; i*i <= n; i++){
        if(n%i == 0){
            divs.pb(i);
            if(i != n/i) divs.pb(n/i);
        }
    }
    sort(all(divs));
    return divs;
}

string blankLine;
int t;
void solve(){
    getline(cin,blankLine);
    string str; cin >> str;
    int n = (int)str.size();
    auto divs_of_n = divisores(n);
    for(auto div_i: divs_of_n){
        string temp = "";
        int e = 0;
        set<string> st;
        while(e < n){
            temp = str.substr(e,div_i);
            e += div_i;
            st.insert(temp);
        }
        if(st.size() == 1){
            cout << div_i << endl;
            if(t != 0) cout << endl;
            break;
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
    cin >> t;
    cin.ignore();
    // t = 1;
    while(t--){
        solve();
    }
    return 0;
}