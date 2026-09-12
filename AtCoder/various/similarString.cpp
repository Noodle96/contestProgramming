#include <bits/stdc++.h>
using namespace std;

bool similarString(string &str1,string &str2 ){
        for(auto e = 0 ;e < str1.size() ; e++){
                if(str1[e] == 'l'){
                        if(str2[e] == 'l') continue;
                        if(str2[e] != '1' )return false;
                }else if(str1[e] == '1'){
                        if(str2[e] == '1') continue;
                        if(str2[e] != 'l')return false;
                }else if(str1[e] == '0'){
                        if(str2[e] == '0') continue;
                        if(str2[e] != 'o') return false;
                }else if(str1[e] == 'o'){
                        if(str2[e] == 'o') continue;
                        if(str2[e] != '0') return false;
                }else{
                        if(str1[e] != str2[e]) return false;
                }
        }
        return true;
}
        
int main(){
        int N; cin>> N;
        string S,T;
        cin>>S;
        cin>>T;
        cout << (similarString(S,T) ? "Yes": "No") << endl;
        return 0;
}
