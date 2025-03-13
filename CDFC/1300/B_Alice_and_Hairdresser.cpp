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

int segments = 0;

void solve(){
    int n,m; cin>>n>>m;
    ll l; cin>>l;
    vector<ll> vec(n);
    for(int i=0;i<n;i++) cin>>vec[i];

    for(int e = 0 ; e < n; e++){
        if(vec[e] > l){
            if(e == 0 || vec[e-1]<= l) segments++;
        }
    }
    while(m--){
        int type; cin>>type;
        if(type == 0){
            cout << segments << endl;
        }else{
            int pos; cin>>pos; pos--;
            ll d; cin>>d;
            if(vec[pos] <= l){
                vec[pos] += d;
                if(vec[pos] > l){
                    bool leftGreaterThanL = pos > 0 && vec[pos-1] > l;
                    bool rightGreaterThanL = pos < n-1 && vec[pos+1] > l;
                    if(leftGreaterThanL && rightGreaterThanL) segments--;
                    if(!leftGreaterThanL && !rightGreaterThanL) segments++;
                }
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
    return 0;
}