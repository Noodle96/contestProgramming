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
map<string, ll> BASE;
vector<string> letters = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P",
                            "Q","R","S","T","U","V","W","X","Y","Z"};
void pre(){
    for(ll i = 0; i < 10; i++){
        BASE[to_string(i)] = i;
    }
    
    for(auto e = 0 ; e < letters.size(); e++){
        BASE[letters[e]] = e+10; 
    }
    // cout <<"size: " <<BASE.size() << endl;
    // for(auto it : BASE){
    //     cout << it.first << " " << it.second << endl;

    // }
}

int maxDigit(string s){
    int ans =  0;
    for(auto e:s){
        ans = max(ans, (int)BASE[string(1,e)]);
    }
    return ans;
}

ll convert(string s, int base){
    ll res = 0;
    ll mul = 1;
    for(int i = s.size()-1; i >= 0; i--){
        res += BASE[string(1,s[i])]*mul;
        mul *= base;
    }
    return res;
}

bool allOne(string s){
    for(auto e:s){
        if(e != '1') return false;
    }
    return true;
}

void solve(){
    string a,b;
    while(cin>>a>>b){
        map<int,ll> A_toBase10,B_toBase10;
        int baseA = maxDigit(a);
        // cout << baseA << endl;
        if(baseA == 0 || baseA == 1){
            baseA = 2;
        }else{
            baseA++;
        }
        for(; baseA <= 36; baseA++){
            ll temp = convert(a,baseA);
            A_toBase10[baseA] = temp;
        }
        int baseB = maxDigit(b);
        if(baseB == 0 || baseB == 1){
            baseB = 2;
        }else{
            baseB++;
        }
        
        for(; baseB <= 36; baseB++){
            ll temp = convert(b,baseB);
            B_toBase10[baseB] = temp;
        }
        bool flag = true;
        for(auto itA: A_toBase10){
            if(flag){
                for(auto itB: B_toBase10){
                    if(itA.second == itB.second){
                        flag = false;
                        cout << a << " (base " << itA.first << ") = " << b << " (base " << itB.first << ")" << endl;
                        break;
                    }
                }
            }else break;
            
        }
        if(flag) cout << a << " is not equal to " << b << " in any base 2..36" << endl;
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