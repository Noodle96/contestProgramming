#include <bits/stdc++.h>
using namespace std;
#define M 1000000007;
using LL = long long;

LL f(LL x,LL y){
    if(y==0) return 1;
    if(x == 0 &&x==y) return 1;
    if(y==1) return x;
    if(y % 2 == 0){
        LL p = f(x,y/2); 
        return (p*p) % M;
    }
    else return (f(x,y-1) * x)%M;
}


int main(){
    
    int q; cin>>q;
    LL x,y;
    while(q--){
        cin>>x>>y;
        x = x%M;
        LL ans = f(x,y);
        cout << ans << endl;

        //fast exponention


        // for (int i = 0; i < y; i++){
        //     ans = (ans*x) %M;
        // }
        // cout << ans << endl;
        
    }
    return 0;
}