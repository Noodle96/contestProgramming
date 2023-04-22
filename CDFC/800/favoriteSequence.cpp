#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    vector<int> vec;
    vector<int> vecTemp;;
    int n;
    while(t--){
        cin>>n;
        vec.resize(n);
        for(int e = 0 ; e < n; e++)cin>> vec[e];
        int iteracion;
        if(n&1) iteracion = (n/2) +1;
        else iteracion = (n/2);
        for(int e = 0 ;e < iteracion ; e++){
            if(e != n-e-1){
                vecTemp.push_back(vec[e]);
                vecTemp.push_back(vec[n-e-1]);
            }else{
                vecTemp.push_back(vec[e]);
            }
            
        }
        for(auto it = vecTemp.begin(); it != vecTemp.end() ; it++){
            cout << *it << " ";
        }cout << endl;
        vec.clear();
        vecTemp.clear();
    }
    return 0;
}