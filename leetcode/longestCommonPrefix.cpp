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

vector<string> vec_dic;
string s;
bool flag;

string lcp(){
    string ans = "";
    for(auto i = 0 ;i < vec_dic[0].size() ; i++){
        auto c_ch = vec_dic[0][i];
        flag = true;
        for(int j = 0;j < vec_dic.size() ;j++){
            if(c_ch != vec_dic[j][i]){
                flag = false;
                break;
            }
        }
        if(flag) ans += c_ch;
        else break;
    }
    return ans;
}

void solve(){
    while(cin>>s){
        vec_dic.push_back(s);
    }
    cout << lcp() << endl;
    // print dict
    // for(auto i:dict){
    //     cout<<i<<endl;
    // }

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