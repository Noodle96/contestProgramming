#include <bits/stdc++.h>
using namespace std;
bool isVowel(const char &c){
    if(c == 'a' or c== 'e' or c== 'i' or c== 'o' or c== 'u')return true;
    return false;
}
int main(){
    string s;
    cin>>s;
    int e = 0;
    for(; e <  s.size()-1; e++){
        if(s[e] != 'n'){
            if(!isVowel(s[e])){
                if(!isVowel(s[e+1])){
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
    }
    if(!isVowel(s[e]) && s[e] != 'n' ){
        cout << "NO" <<endl;
        return  0;
    }
    cout << "YES" <<endl;
    return 0;
}