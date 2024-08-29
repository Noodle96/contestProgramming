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

ll convert(ll num, int base){
    ll res = 0;
    ll mul = 1;
    while(num){
        res += (num%10)*mul;
        mul *= base;
        num /= 10;
    }
    return res;
}

int digitMax(ll a, ll b, ll c){
    int res = 0;
    while(a){
        res = max(res, (int)(a%10));
        a /= 10;
    }
    while(b){
        res = max(res, (int)(b%10));
        b /= 10;
    }
    while(c){
        res = max(res, (int)(c%10));
        c /= 10;
    }
    return res;
}

bool allOne(ll a, ll b, ll c){
    while(a){
        if(a%10 != 1) return false;
        a /= 10;
    }
    while(b){
        if(b%10 != 1) return false;
        b /= 10;
    }
    while(c){
        if(c%10 != 1) return false;
        c /= 10;
    }
    return true;
}

void solve(){
    ll a,b,c;
    char op,same;
    cin>>a>>op>>b>>same>>c;
    // cout << "A: " << a << " B: " << b << " C: " << c << endl;
    int digMax = digitMax(a,b,c);
    int base;
    if(digMax == 0){
        base = 2;
    }
    else if(digMax == 1 && allOne(a,b,c)){
        base = digMax;
    }else{
        base = digMax+1;
    }
    for(; base <= 20; base++){
        // cout << "base: " << base << endl;
        int a_,b_,c_;
        a_ = convert(a,base);
        b_ = convert(b,base);
        c_ = convert(c,base);
        // cout << "a: " << a_ << " b: " << b_ << " c: " << c_ << endl;
        if(a_+b_ == c_){
            cout<<base<<endl;
            return;
        }
    }
    cout << 0 << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t; cin>>t;
    while(t--){
        solve();
    }
    return 0;
}