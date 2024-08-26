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

int gcd(int a,int b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

clock_t startTime;
double getCurrentTime() {
    return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
ll n, num,den;
const int N =1e7;
vector<ll> cantor(N);
void solve(){
    while(cin>>n){
        // for(auto e: cantor){
        //     cout << e << " " ;
        // }cout << endl;
        
        // cout << "cantor: " << endl;
        // for(int e =0  ; e < 10 ; e++){
        //     cout << cantor[e] << " ";
        // }cout << endl;
        // cout << cantor.size() << " -> " << cantor[N-1] << endl; 
        auto lower = lower_bound(all(cantor),n);
        int idx = lower - cantor.begin();
        if(n == cantor[idx]){
            // cout << "algo" << endl;
            if(idx % 2 == 0){
                num = 1;
                ll total = idx+2;
                den = total -num;
            }else{
                den = 1;
                ll total = idx+2;
                num = total - den;
            }
            cout <<"TERM " << n << " IS " <<num << "/" << den << endl;
        }else{
            idx--;
            if(idx%2 == 0){
                num = n - cantor[idx];
                ll total = idx+3;
                den = total - num;
            }else{
                den = n - cantor[idx];
                ll total = idx+3;
                num = total - den;
            }
            cout <<"TERM " << n << " IS " <<num << "/" << den << endl;
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
    iota(all(cantor),1);
    for(int i = 1; i < N; i++){
        cantor[i] = cantor[i-1] + cantor[i];
    }
    solve();
    return 0;
}