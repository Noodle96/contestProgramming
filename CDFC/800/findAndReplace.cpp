#include <bits/stdc++.h>
using namespace std;
bool verifyIgualdad(int before, int current, string &str){
    if(str[before] == str[current])return true;
    return false;
}
string negacion(char c){
    if(c == '1')return "0";
    return "1";
}
int main(){
    int t; cin>>t;
    int n;
    string str;
    string strTemp="1";
    unordered_map<char,string> hash;
    char temp;
    bool flag;
    while(t--){
        flag = false;
        cin>>n;
        cin>>str;
        hash[str[0]] = "1";
        for(int e = 1 ; e < n ; e++){
            // cout << "hash[str[e]]: " << hash[str[e]] << endl;
            if(hash[str[e]] != ""){
                strTemp += hash[str[e]];
                // cout << "strTemp if: " << strTemp << endl;
                if(verifyIgualdad(e-1,e, strTemp)){
                    cout << "NO" << endl;
                    flag = true;
                    break;
                }
            }else{
                // cout << "strTemp: " << strTemp << endl;
                temp = strTemp[e-1];
                // cout << "temp: " << temp << endl;
                strTemp += negacion(temp);
                // cout << "strTemp else : " << strTemp << endl;
                // cout << "to_string(negacion(temp)): " << negacion(temp) << endl; 
                hash[str[e]] = negacion(temp);
            }
        }
        // cout << "printHash: " << endl;
        // for(auto it = hash.begin(); it != hash.end() ; it++){
        //     cout << it->first << " : " << it->second << endl;
        // }
        hash.clear();
        strTemp = "1";
        if(!flag)cout << "YES" << endl;
    }
    return 0;
}