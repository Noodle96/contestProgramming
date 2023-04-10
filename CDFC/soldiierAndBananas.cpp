#include <bits/stdc++.h>
using namespace std;
using LL = long long ;
int main(){
    LL k,n,w;
    cin>>k>>n>>w;
    LL total = k * (w*(w+1)/2);
    cout << (n >= total ? 0 : total - n) << endl;
    return 0;
}