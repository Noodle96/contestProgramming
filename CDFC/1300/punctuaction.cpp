#include <bits/stdc++.h>
using namespace std;

bool after(int e , string &str){
    if(str[e+1] == ' ' or str[e+1]== ',' or str[e+1]== '.' or str[e+1]== '!' or str[e+1]== '?')return true;
    return false;
}
int main(){
    string str;
    getline(cin,str);
    bool flag;
    int e = 0;
    string result = "";
    if(str[e]==' ')e++;
    for( ; e < str.size()-1; e++){
        if(str[e] == ' '){
            if(!after(e,str)){
                result += str[e];
            }
        }
        else if(str[e] == ',' or str[e] == '.' or str[e] == '!' or str[e] == '?'){
            if(!after(e,str)){
                result += str[e];
                result += " ";
            }else{
                result += str[e];
            }
        }else{
            result += str[e];
        }
    }
    if(str[e] != ' ')result += str[e];
    cout << result << endl;
    return 0;
}