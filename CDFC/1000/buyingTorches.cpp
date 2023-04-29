#include <bits/stdc++.h>
using namespace std;
long long f(long long x, long long y, long long k){
    if((y+1)*k < x) return 1 + k;
    long long modulo = ((y+1)*k -x) % (x-1);
    long long division = ((y+1)*k -x) / (x-1); ;
    long long techo = (modulo == 0 ? division +1 : division +2);
    return k + techo;

}
int main(){
    int t;cin>>t;
    long long x,y,k;
    while(t--){
        cin>>x>>y>>k;
        cout << f(x,y,k) << endl;
    }
    return 0;
}