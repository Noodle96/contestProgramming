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

void solve(){
    int B,N;
    while(cin>>B>>N){
        if(B != 0 || N != 0){
            vector<int> bank(B);
            for(int e = 0 ;e < B ;e++) cin>>bank[e];
            for(int e = 0 ; e < N; e++){
                int D,C,V; cin>> D>>C>>V;
                D--, C--;
                bank[D] -= V;
                bank[C] += V;
            }
            bool ans = true;
            for(int e = 0 ;e < B ;e++){
                ans &= (bank[e] >= 0);
            }
            cout << (ans ? "S" : "N") << endl;
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