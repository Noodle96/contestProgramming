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
bool isCreciente(vector<int> &vec){
    for(int e = 1 ;e < vec.size() ; e++){
        if(vec[e] <= vec[e-1]){
            return false;
        }
    }
    return true;
}
void solve(){
    vector<int> vec(5);
    for(int e =0 ;e < 5 ; e++){
        cin>>vec[e];
    }
    bool ans =  false;
    for(int e = 0 ; e < 4; e++){
        if(vec[e] != e+1){
            if(vec[e] != vec[e+1]-1 ){
                ans = true;
                swap(vec[e], vec[e+1]);
                break;
            }
        }
    }
    if(isCreciente(vec) && ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
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