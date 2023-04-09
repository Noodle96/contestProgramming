#include <bits/stdc++.h>
using namespace std;
int main(){
    string str1,str2;
    getline(cin,str1); getline(cin,str2);
    //convert tolower
    for(int e = 0 ; e < str1.size(); e++){
        str1[e] = tolower(str1[e]);
        str2[e] = tolower(str2[e]);
    }

    int contador = 0;
    for (auto e = 0; e < str1.size(); e++){
        if(str1[e] > str2[e]){
            contador++;
        }else if(str1[e] < str2[e]){
            contador--;
        }
    }
    // cout << contador << endl;
    // cout << (contador < 0 ? -1 : (contador > 0 ? 1 : 0 )) << endl;
    cout << (str1 > str2 ? 1 : (str2 > str1 ? -1 : 0)) << endl;
    return 0;
}