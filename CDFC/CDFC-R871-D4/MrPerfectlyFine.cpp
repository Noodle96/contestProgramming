#include <bits/stdc++.h>
using namespace std;
int evaluate(unordered_map<string, int> &mapp){
    if(!mapp["11"] && !mapp["10"])return -1;
    if(!mapp["11"] && !mapp["01"]) return -1;
    if(mapp["11"] && mapp["10"] && mapp["01"])return min(mapp["11"], mapp["10"]+mapp["01"]);
    if(mapp["11"]) return mapp["11"];
    return mapp["10"] + mapp["01"];
}
int main(){
    int t;cin>>t;
    int n;
    unordered_map<string, int> map;
    int m; string str;
    int k;
    while(t--){
        cin>>n;k =0;
        for(int e = 0 ; e < n; e++){
            cin>>m; cin>>str;
            if(map[str]){
                map[str] = min(m, map[str]);
            }else{//no existe
                map[str] = m;
                // if(k)map[str] = min(m, map[str]);
                // else{
                //     map[str] = m;k++;
                // }
            }

            
        }
        // for(auto it = map.begin(); it != map.end() ; it++){
        //     cout << it->first << " : " << it->second << endl;
        // }
        cout << evaluate(map) << endl;
        map.clear();
    }
    return 0;
}