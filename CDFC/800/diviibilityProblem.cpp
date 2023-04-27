#include <bits/stdc++.h>
using namespace std;
int f(int a, int b){
    int cc = (!(a%b) ? a/b : a/b +1);
    return (cc) *b -a;
}
int main(){
    int t; cin>>t;
    int a,b;
    while(t--){
        cin>>a>>b;
        cout << f(a,b) << endl;
    }
    return 0;
}