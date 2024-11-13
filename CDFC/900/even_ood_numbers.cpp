#include <bits/stdc++.h>
using namespace std;
using LL = long long;
LL f(LL n, LL k){
    LL middle = (!(n%2) ? n/2 : n/2 +1);
    if(k <= middle) return k*2 -1;
    return (k-middle)*2;


}
int main(){
    LL n,k; cin>>n>>k;
    cout << f(n,k) << endl;
    return 0;
}