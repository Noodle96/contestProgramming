/*
==========================================================
|  Archivo       : 10298_Power_Strings.cpp
|  Autor         : Russell
|  Fecha         : 2025-09-13 16:32
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

int divisores(int n){
    int cnt = 0;
    for(int i = 1; i*i <= n; i++){
        if(n%i == 0){
            cnt++;
            if(i != n/i) cnt++;
        }
    }
    return cnt;
}

vector<int> divisoresV(int n){
    vector<int> divs;
    for(int i = 1; i*i <= n; i++){
        if(n%i == 0){
            divs.push_back(i);
            if(i != n/i) divs.push_back(n/i);
        }
    }
    return divs;
}


void solve2(){
    int n = 1e6;
    int maximo = INT_MIN;
    map<int,int> memo;
    for(int e = 1 ; e <= n; e++){
        int ans = divisores(e);
        memo[ans]++;
        maximo = max(maximo,ans);
    }
    int total = 0;
    for(auto p: memo){
        cout << p.first << " " << p.second << endl;
        total += p.second;
    }
    cout << endl;
    cout << "maximo: " << maximo << endl; // 240 -> maximo 240 divisores
    cout << "total: " << total << endl; // 1e6
}
void solve(){
    string str;
    while(cin >> str){
        if(str == ".") break;
        int n = (int)str.size();
        // for(int i = 1; i <= n; i++){
        //     if(n%i == 0){
        //         string temp = str.substr(0,i);
        //         string constructed = "";
        //         for(int j = 0; j < n/i; j++){
        //             constructed += temp;
        //         }
        //         if(constructed == str){
        //             cout << n/i << endl;
        //             break;
        //         }
        //     }
        // }
        auto divs_of_n = divisoresV(n);
        sort(all(divs_of_n));

        for(auto div_i: divs_of_n){
            string temp = "";
            int e = 0;
            set<string> st;
            while(e < n){
                auto temp = str.substr(e,div_i);
                e += div_i;
                st.insert(temp);
            }
            if(st.size() == 1){
                cout << n/div_i << endl;
                break;
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
    int t;
    //cin >> t;
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}