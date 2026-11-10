#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string str){
    int length = str.size();
    bool flag;
    for(int i=0;i < length ;i++){
        if(str[i] != str[length-i-1]) return false;
    }
    return true;
}
int f(string str){
    int length = str.size();
    string strTemp;
    for(int e = 0; e < length ; e++){
        // cout << str.substr(0,length-e-1) << endl;
        strTemp = str.substr(0,length-e-1);
        // cout << strTemp << endl;
        if( !isPalindrome(strTemp) ) return strTemp.size();
    }
    return -1;

}
int main(){
    // cout << isPalindrome(str) << endl;
    int t; cin>>t;
    string str;
    while(t--){
        cin>>str;
        cout << f(str) <<endl;
    }
    
    return 0;
}