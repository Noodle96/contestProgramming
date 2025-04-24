/*
==========================================================
|  Archivo       : E2_Letter_Strings.cpp
|  Autor         : Russell
|  Fecha         : 2025-04-23 19:08
|--------------------------------------------------------
|  Tópicos utilizados:
|  - DataStructure: Unordered_map
|  - String
|  - Math
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
    int n; cin>>n;
    string buffer;
    unordered_map<char,vector<char>> hashMapFirst, hashMapSecond;
    hashMapFirst.clear();
    hashMapSecond.clear();
    while(n--){
        cin>>buffer;
        // cout << "buffer: " << buffer << endl;
        hashMapFirst[buffer[0]].pb(buffer[1]);
        hashMapSecond[buffer[1]].pb(buffer[0]);
    }
    //print hashMap
    
    // for(auto &[x_key, valueList]: hashMapFirst){
    //     cout << x_key << " : ";
    //     for(int e = 0; e < valueList.size(); e++){
    //             cout << valueList[e] << " ";
    //     }
    //     cout << endl;
    // }
    // return;
            
    ll ans = 0 ;
    for(auto &[x_key, valueList]: hashMapFirst){
        size_t size = valueList.size();
        vector<vector<ll>> prefix(size, vector<ll>(11));  
        for(auto ch = 'a' ; ch <= 'k';ch++ ){
            prefix[size-1][ch-'a'] = (valueList[size-1] == ch) ? 1 : 0;
        }
        for(int i = size-2; i >= 0; i--){
            for(auto ch = 'a' ; ch <= 'k';ch++ ){
                prefix[i][ch-'a'] = prefix[i+1][ch-'a'] + ((valueList[i] == ch) ? 1 : 0);
            }
        }
        // cout << "valueList" << endl;
        // for(auto v: valueList){
        //     cout << v << " ";
        // }cout << endl;
        // cout << "prefix" << endl;
        // for(int i = 0; i < size; i++){
        //     for(auto ch = 'a' ; ch <= 'k';ch++ ){
        //         cout << prefix[i][ch-'a'] << " ";
        //     }cout << endl;
        // }cout << endl << endl;
        size = valueList.size();
        // cout << "size: " << size << endl;
        for(int e = 0 ; e < size;e++){
            auto key = valueList[e];
            // cout<< "\tkey: " << key << endl;
            auto frecuencyKey = prefix[e][key-'a'];
            // cout << "\tfrecuencyKey: " << frecuencyKey << endl;
            ans += (size - e -1 - (frecuencyKey -1));
            // cout << "\tans_e: " << ans << endl;
        }
        // cout << "ans_i : " << ans << endl;
    }
    for(auto &[x_key, valueList]: hashMapSecond){
        size_t size = valueList.size();
        vector<vector<int>> prefix(size, vector<int>(11));  
        for(auto ch = 'a' ; ch <= 'k';ch++ ){
            prefix[size-1][ch-'a'] = (valueList[size-1] == ch) ? 1 : 0;
        }
        for(int i = size-2; i >= 0; i--){
            for(auto ch = 'a' ; ch <= 'k';ch++ ){
                prefix[i][ch-'a'] = prefix[i+1][ch-'a'] + ((valueList[i] == ch) ? 1 : 0);
            }
        }
        for(int e = 0 ; e < size;e++){
            auto key = valueList[e];
            auto frecuencyKey = prefix[e][key-'a'];
            ans += (size - e -1 - (frecuencyKey -1));
        }
    }
    cout << ans << endl;
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