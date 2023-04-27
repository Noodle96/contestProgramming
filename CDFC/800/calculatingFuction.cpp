#include <bits/stdc++.h>
using namespace std;
long long f(long long n){
    if(!(n&1)) return n/2;
    return -n + f(n-1);
}
int main(){
    long long n; cin>>n;
    cout << f(n) << endl;
    return 0;
}