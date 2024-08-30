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

map<string,int> BASE_str_int;
map<int, string> BASE_int_str;
void pre(){
    for(int i = 0; i < 10; i++){
        BASE_str_int[to_string(i)] = i;
        BASE_int_str[i] = to_string(i);
    }
    for(int i = 10; i <= 35; i++){
        char c = (i-10+'A');
        string s(1,c);
        BASE_str_int[s] = i;
        BASE_int_str[i] = s;
    }
    // for(auto e: BASE){
    //     cout << e.first << " " << e.second << endl;
    // }
}

ll convertBaseNToBase10(string num, int base){
    ll res = 0;
    ll mul = 1;
    // cout << "num: " <<num << endl;
    for(int i = num.size()-1; i >= 0; i--){
        // cout << "num[i]: " << num[i] << endl;
        char c = num[i];
        string s(1,c);
        // cout << "debug: " << (BASE_str_int[s]) << endl;
        res += mul*(BASE_str_int[s]);
        mul *= base;
    }
    return res;
}

string convertBase10ToBaseN(ll num, int base){
    string res = "";
    while(num){
        res += BASE_int_str[num%base];
        num /= base;
    }
    reverse(all(res));
    if(res.size() == 0) res = "0";
    // cout << res << endl;
    return res;
}

void solve(){
    string line;
    int from, to;
    while(cin>>line>>from>>to){
        // cout << line << " " << from << " " << to << endl;
        ll num_base_10 = convertBaseNToBase10(line,from);
        // cout << "base 10: " << num_base_10 << endl;
        string res = convertBase10ToBaseN(num_base_10,to);
        // cout << res << endl;
        if(res.size() > 7){
            cout << "  ERROR" << endl;
        }else{
            cout << setw(7) << res << endl;
            // cout << res << endl;
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
    pre();
    solve();
    return 0;
}