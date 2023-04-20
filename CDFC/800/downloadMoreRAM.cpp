#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    int n,k;
    while(t--){
        cin>>n>>k;
        vector<pair<int,int>> costos(n);
        for(auto it = costos.begin(); it != costos.end() ; it++){
            cin>> it->first;
        }
        for(auto it = costos.begin(); it != costos.end() ; it++){
            cin>> it->second;
        }
        // for(auto it = costos.begin(); it != costos.end() ; it++){
        //     cout << it->first << " : " << it->second << endl;
        // }
        sort(costos.begin(), costos.end());
        for(auto it =  costos.begin() ; it != costos.end(); it++){
            if(k>= it->first){
                k+= it->second;
            }else{
                break;
            }
        }
        cout << k << endl;
    }
    return 0;
}