#include <bits/stdc++.h>
using namespace std;
int minimunNumberDays(string &str){
    unordered_map<char,int> memory;
    int cont = 0;
    for(int e = 0 ;e < str.size() ; e++){
        memory[str[e]]++;
        if(memory.size() == 4){
            // cout << "e: " << e << endl;
            cont++;
            e--;
            memory.clear();
        }
    }
    // cout << "current memory: "<<memory.size() << endl;
    if(memory.size() != 0) cont++;
    return cont;
}
int main(){
    int t; cin>>t;
    string str;
    while(t--){
        cin>>str;
        cout << minimunNumberDays(str) <<endl;
    }
    return 0;
}