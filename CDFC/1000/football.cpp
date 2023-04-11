#include <bits/stdc++.h>
using namespace std;
void printMap(map<string,int> &map){
    for(auto it = map.begin() ; it!= map.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
}
int main(){
    map<string,int> match;
    int n; cin>>n;
    string temp;
    while(n--){
        cin>>temp;
        match[temp]++;
    }
    // printMap(match);
    auto first = match.begin();
    auto second = ++match.begin();
    if(second != match.end()){
        cout << (first->second > second->second ? first->first : second->first ) << endl;
    }
    else{
        cout << first->first<< endl;
    }
    return 0;
}