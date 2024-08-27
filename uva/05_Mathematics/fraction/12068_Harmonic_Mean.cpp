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

class Fraction{
    private:
        ll num;
        ll den;
    public:
        Fraction(ll n,ll d){
            num = n;
            den = d;
        }
        ll getNum(){return num;}
        ll getDen(){return den;}
        void setNum(ll n){num = n;}
        void setDen(ll d){den = d;} 
        ~Fraction(){}
        Fraction operator+(const Fraction& f){
            ll n = num*f.den + f.num*den;
            ll d = den*f.den;
            ll g = gcd(n,d);
            return Fraction(n/g,d/g);
        }
};

int N;
void solve(int caso){
    cin>>N;
    vector<Fraction> fr;
    for(int e = 0 ; e < N; e++){
        ll a;cin>>a;
        fr.push_back(Fraction(1,a));
    }
    Fraction ans = fr[0];
    for(int e = 1; e < fr.size() ; e++){
        ans = ans + fr[e];
    }
    auto temp = ans;
    ans.setNum(N*temp.getDen());
    ans.setDen(temp.getNum());
    ll g = gcd(ans.getNum(),ans.getDen());
    ans.setNum(ans.getNum()/g);
    ans.setDen(ans.getDen()/g);
    cout << "Case " << caso << ": "<< ans.getNum() << "/" << ans.getDen() << endl;

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifdef DEBUG
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;cin>>t;
    int caso = 1;
    while(t--) solve(caso++);
    return 0;
}