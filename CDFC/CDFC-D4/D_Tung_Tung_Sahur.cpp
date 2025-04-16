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
string s,p;
void solve(){
    cin>>p>>s;
    if(p[0] != s[0]){
        cout << "NO" << endl;
        return;
    }
    int contL = 0, contR = 0;;
    vector<int> dataPL, dataPR;
    for(auto e = 0 ; e < p.size(); e++){
        if(p[e] == 'L'){
            contL++;
        }else{
            if(contL != 0){
                dataPL.pb(contL);
                contL = 0;
            }
        }
    }
    if(contL != 0){
        dataPL.pb(contL);
        contL = 0;
    }
    for(auto e = 0 ; e < p.size(); e++){
        if(p[e] == 'R'){
            contR++;
        }else{
            if(contR != 0){
                dataPR.pb(contR);
                contR = 0;
            }
        }
    }
    if(contR != 0){
        dataPR.pb(contR);
        contR = 0;
    }

    // to s
    contL = 0; contR = 0;
    vector<int> dataSL, dataSR;
    for(auto e = 0 ; e < s.size(); e++){
        if(s[e] == 'L'){
            contL++;
        }else{
            if(contL != 0){
                dataSL.pb(contL);
                contL = 0;
            }
        }
    }
    if(contL != 0){
        dataSL.pb(contL);
        contL = 0;
    }

    for(auto e = 0 ; e < s.size(); e++){
        if(s[e] == 'R'){
            contR++;
        }else{
            if(contR != 0){
                dataSR.pb(contR);
                contR = 0;
            }
        }
    }
    if(contR != 0){
        dataSR.pb(contR);
        contR = 0;
    }
    // cout << dataPL.size() << " " << dataSL.size() << endl;
    // cout << dataPR.size() << " " << dataSR.size() << endl;
    if( dataPL.size() != dataSL.size() ){
        cout << "NO" << endl;
        return;
    }
    if( dataPR.size() != dataSR.size() ){
        cout << "NO" << endl;
        return;
    }
    // valid L
    bool ans =  true;
    for(int e = 0 ;e < dataPL.size() ; e++){
        ans &= (dataPL[e] <= dataSL[e] && dataSL[e] <= 2*dataPL[e]);
    }
    for(int e = 0 ;e < dataPR.size() ; e++){
        ans &= (dataPR[e] <= dataSR[e] && dataSR[e] <= 2*dataPR[e]);
    }
    cout << (ans ? "YES" : "NO") << endl;
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