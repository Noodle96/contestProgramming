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

unordered_map<char,int> hash;

bool validAnagram(string s, string p){
    for(auto ch: s){
        ::hash[ch]++;
    }
    for(auto ch: p){
        if(::hash[ch] == 0) return false;
        ::hash[ch]--;
    }
    for(auto it: ::hash){
        if(it.second != 0) return false;
    }
    return true;
}
void solve(){
    string s,p;
    cin>>s>>p;
    if(validAnagram(s,p)){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
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