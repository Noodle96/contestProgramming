#include <bits/stdc++.h>
using namespace std;
void f(string &str){
    map<char,int> map;
    auto before = str.begin();
    map[*before]++;
    auto current = ++str.begin(); 
    int cont = 0;
    for(; current != str.end(); current++){
        map[*current]++;
        before = current;
    }
    if(map.size() == 2) cout << "Yes" << endl;
    else cout << "No" << endl;
}
int main(){
    string s; cin>>s;
    f(s);
    return  0;
}