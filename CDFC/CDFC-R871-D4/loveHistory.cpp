#include <bits/stdc++.h>
using namespace std;
int differ(string str){
    string test = "codeforces";
    int cont = 0;
    for(auto e = 0 ; e < str.size(); e++){
        if(str[e] != test[e])cont++;
    }
    return cont;

}
int main(){
    int t;cin>>t;
    string s;
    while(t--){
        cin>>s;
        cout << differ(s) << endl;
    }
    return 0;
}