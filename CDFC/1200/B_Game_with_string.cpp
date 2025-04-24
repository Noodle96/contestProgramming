/*
==========================================================
|  Archivo       : C_Minimum_Notation.cpp
|  Autor         : Russell
|  Fecha         : 2025-04-24 11:14
|--------------------------------------------------------
|  Tópicos utilizados:
|  - DataStructure: Stack
|  - Implementation
|  - *1200
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
    string str;
    cin>>str;
    bool first = false, second = true;
    stack<char> st;
    st.push(str[0]);
    for(int e = 1 ;e < str.size() ; e++){
        if(st.empty()){
            st.push(str[e]);
            continue;
        }
        char last = st.top();
        if(str[e] == last){
            st.pop();
            first = !first;
            second = !second;
        }else{
            st.push(str[e]);
        }
    }
    cout << (first ? "Yes" : "No") << endl;
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