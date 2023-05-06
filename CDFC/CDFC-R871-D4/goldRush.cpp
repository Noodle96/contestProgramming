#include <bits/stdc++.h>
using namespace std;
bool evaluate(int n, int m){
    // cout << n << endl;
    if(n==m) return true;
    if(n < m) return false;
    if(n%3 != 0) return false; 
    return evaluate(2*n/3,m) || evaluate(n/3,m) ;
}
int main(){
    int t; cin>>t;
    int n,m;
    while(t--){
        cin>>n>>m;
        cout << (evaluate(n,m) ? "YES" : "NO") << endl;
    }
    return 0;
}