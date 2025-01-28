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

int gcd(int a,int b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

map<int, int> mapTotal;

void saveDivisoresType(int num, string type){
    if(type == "num"){
         for(int e = 2; e <= sqrt(num); e++){
            while(num % e == 0){
                // cout << e  << " ";
                mapTotal[e]++;
                num /= e;
            }
        }
        if(num > 1){
            mapTotal[num]++;
            // cout << num << endl;
        }
    }else{ // denominador
         for(int e = 2; e <= sqrt(num); e++){
            while(num % e == 0){
                // cout << e  << " ";
                mapTotal[e]--;
                num /= e;
            }
        }
        if(num > 1){
            mapTotal[num]--;
            // cout << num << endl;
        }
    }
}


__int128_t combinations(int n, int m){
    if( m < n-m) m = n-m;
    __int128_t ans = 1;
    for(int i = m+1; i <= n; i++){
        saveDivisoresType(i,"num");
    }
    // cout << "mapTotal: " << endl;
    // for(auto e: mapTotal){
    //     cout << e.first << " " << e.second << endl;
    // }
    for(__int128_t i = 1; i <= n-m; i++){
        saveDivisoresType(i,"den");
    }
    // cout << "denominador: " << endl;
    // for(auto e: mapTotal){
    //     cout << e.first << " " << e.second << endl;
    // }
    for(auto e: mapTotal){
        if(e.second > 0){
            ans *= pow(e.first,e.second);
        }
    }
    return ans;
}

__int128_t stringToInt128(const string& s) {
    __int128_t result = 0;
    bool isNegative = (s[0] == '-'); // Detectar si el número es negativo
    for (size_t i = (isNegative ? 1 : 0); i < s.size(); ++i) {
        result = result * 10 + (s[i] - '0');
    }
    return isNegative ? -result : result;
}
void readInt128(__int128_t& x) {
    string input;
    cin >> input;
    x = stringToInt128(input);
}

string printInt128(__int128_t x) {
    if (x == 0) {
        return "0";
    }
    string result;
    while (x > 0) {
        result = char('0' + x % 10) + result;
        x /= 10;
    }
    return result;
}

void solve(){
    ll n_,m_;
    while(cin>>n_>>m_){
        __int128_t n = n_, m = m_;
        mapTotal.clear();
        if(n != 0 || m != 0){
            if(n==m){
                cout << printInt128(n) << " things taken " << printInt128(m) << " at a time is 1 exactly." << endl;
            }else{
                __int128_t ans = combinations(n,m);
                cout << printInt128(n) << " things taken " << printInt128(m) << " at a time is " << printInt128(ans) << " exactly." << endl;
            }
        }
    }
}

void solve2(){
    int a; cin>>a;
    // saveDivisoresType(a);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    solve();
    // solve2();
    return 0;
}