#include <bits/stdc++.h>
using namespace std;
bool isMale(string &s){
    map<char,int> map;
    for(int e = 0 ; e < s.size(); e++) map[s[e]]++;
    return (map.size() & 1);
}
int main(){
    string s; cin>>s;
    cout << (isMale(s) ? "IGNORE HIM!" :"CHAT WITH HER!" ) << endl;
    return 0;
}