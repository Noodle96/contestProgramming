#include <bits/stdc++.h>
using namespace std;
#define M 1000000007;
using LL = long long;

LL f(LL x,LL y){
    if(y==0) return 1;
    // if(x == 0 &&x==y) return 1;
    // if(y==1) return x;
    if(y % 2 == 0){
        LL p = f(x,y/2); 
        return (p*p) % M;
    }
    else return (f(x,y-1) * x)%M;
}


int main(){
    
    int q; cin>>q;
    LL x,y,z;
    while(q--){
        cin>>x>>y>>z;
        // y = y % M;
        LL ans = f(y,z);
        ans = ans % M;
        cout << ans << endl;
        // x = x%M;
        ans = f(x,ans);
        cout << ans << endl;
    }
    return 0;
}