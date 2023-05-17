#include <bits/stdc++.h>
using namespace std;
bool f(string &str, int n){
    int cont = 0;
    for(int e = 0 ;e < n ; e++){
        if (str[e] == 'T') cont++;
    }
    if(cont == n-cont){
        if(str[n-1] == 'A') return true;
        return false; 
    }
    if(cont > n-cont) return true;
    return false;
}
int main(){
    int n; cin>>n;
    string s; cin>>s;
    cout << (f(s,n) ? 'T': 'A')<< endl;
    return 0;
}