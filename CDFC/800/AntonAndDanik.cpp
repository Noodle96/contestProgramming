
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    string games;
    cin>> games;
    auto size = games.size();
    map<char,int> map;
    while(size--){
        map[games[size+1]]++;
    } map[games[0]]++;
    for(auto it = map.begin() ; it != map.end(); it++){
        //cout << it->first << " " << it->second << endl;        
    }
    cout << (map['D'] == map['A'] ? "Friendship": (map['D'] > map['A'] ? "Danik": "Anton" ) ) << endl;
    return 0;
}
