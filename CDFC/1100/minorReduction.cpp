#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    for(int i=0;i<t;i++){
        string s;
        cin>>s; 
        int pos=0;
        for(int j=s.length()-1;j>0;j--){
            if(((s[j]-'0') + (s[j-1]-'0')) >= 10){
                pos=j-1;break;
            }
        }
        cout<< s.substr(0,pos) << ((s[pos]-'0') + (s[pos+1]-'0')) << s.substr(pos+2) <<endl;
    }
    return 0;
}