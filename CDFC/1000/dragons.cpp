#include <bits/stdc++.h>
using namespace std;
int main(){
    int s,n; cin>>s>>n;
    vector<pair<int,int>> map;
    int x,y;
    while(n--){
        cin>>x>>y;
        map.push_back(make_pair(x,y));
    }
    sort(map.begin(), map.end());
    // for(auto it = map.begin(); it != map.end() ; it++){
    //     cout << it->first << ":" << it->second << endl;
    // }
    for(auto it = map.begin(); it != map.end(); it++){
        if(s > it->first) s+= it->second;
        else{
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}