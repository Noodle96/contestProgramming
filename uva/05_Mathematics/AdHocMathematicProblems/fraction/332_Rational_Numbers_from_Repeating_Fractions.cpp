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

int caso = 1;
int j;

string decimalLenK(string s, int k){
    string ans;
    int e = 0 ;
    for(; e < s.size(); e++){
        if(s[e] == '.'){
            ans += s[e];
            break;
        }
        else ans += s[e];
    }
    e++;
    int j = 0;
    for(; j < k; j++){
        ans += s[e+j];  
    }
    return ans;
}


ld stringToDouble(string s){
    // cout << "DEBUG() stringToDouble " << endl;
    ld ans = 0;
    int i = 0;
    while(i < s.size() && s[i] != '.'){
        ans = ans*10 + (s[i]-'0');
        i++;
    }
    if(i == s.size()) return ans;
    i++;
    ld dec = 0;
    ld pot = 1;
    // cout << "i before: " << i << endl;
    while(i < s.size()){
        dec = dec*10 + (s[i]-'0');
        pot *= 10;
        // cout << "dec: " << dec << endl;
        // cout << "pot: " << pot << endl;
        i++;
    }
    // cout << "i after: " << i << endl;
    // cout << "ans: " << ans << endl;
    // cout << "dec/pot: " << dec/pot << endl; 
    return ans + dec/pot;
    // ld ans;
    // stringstream ss(s);
    // ss >> ans;
    // return ans;
}


ll toStringPos(string s, int pos){
    int e = 0 ;
    string ans;
    for(; e < s.size(); e++){
        if(s[e] == '.'){
            break;
        }else{
            ans += s[e];
        }
    }
    e++;
    // cout << "ans: " << ans << endl;
    for(int j = 0 ; j < pos; j++){
        ans += s[e+j];
    }
    // cout << "ans: " << ans << endl;
    stringstream ss(ans);
    ll ans2;
    ss >> ans2;
    return ans2;
}


ll Pow(ll x, ll y){
    if(y == 0) return 1;
    if(y&1) return x*Pow(x*x,y/2);
    else return Pow(x*x,y/2);
}

int getK(string s){
    int e = 0;
    for(; e < s.size(); e++){
        if(s[e] == '.'){
            break;
        }
    }
    if(e == s.size()) return 0;
    return s.size()-e-1-j;
}

void solve(){
    while(cin>>j){
        if(j == -1){
            break;
        }else{
            string decimal;
            cin>>decimal;
            // cout << "decimal: " << decimal << endl;
            int k = getK(decimal);
            // cout << k << endl;
            if(j == 0){
                // cout << "j==0" << endl;
                // ll num = Pow(10,k)*stringToDouble(decimal);
                ll num = toStringPos(decimal,k);
                ll den = Pow(10,k);
                ll gcd_ = gcd(num,den);
                cout << "Case " << caso++ << ": " << num/gcd_ << "/" << den/gcd_ << endl;
            }else{
                // cout << "j: " << j << " k: " << k << endl;
                // ld X = stringToDouble(decimal);
                // cout << "x: " << X << endl;
                // cout << "left01: " << Pow(10,k+j) << endl;
                // cout << "left02: " << typeid(Pow(10,k+j)*X).name() << endl; 
                ll left = toStringPos(decimal,k+j);
                // cout << "left: " << left << endl;
                ll right = toStringPos(decimal,k);
                // cout << "right: " << right << endl;
                ll num = left-right;
                // cout << "num: " << num << endl;
                ll den = Pow(10,k+j)-Pow(10,k);
                // cout << "den: " << den << endl;
                // cout << "num: " << num << " den: " << den << endl;
                ll gcd_ = gcd(num,den);
                // cout << "gcd: " << gcd_ << endl;

                // cout << "hola k != 0" << endl;
                cout << "Case " << caso++ << ": " << num/gcd_ << "/" << den/gcd_ << endl;
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
    solve();
    // cout << decimalLenK("0.457", 4) << endl;
    // double a = 3.123;
    // int b =  100;
    // int c = a*b;
    // cout << c << endl;
    // cout << toStringPos("43.8998",0)*2<< endl;
    return 0;
}