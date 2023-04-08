#include <bits/stdc++.h>
using namespace std;
using LL  = long long ;
int main(){
    int n; cin>>n;
    int n_= n;
    vector<LL> vector1,vector2;
    LL temp;
    while(n--){
        cin>>temp;
        vector1.push_back(temp);
    }
    while(n_--){
        cin>>temp;
        vector2.push_back(temp);
    }
    LL operations = 0;
    bool bandera  = true;
    for(int e = 0 ;e < vector1.size() ; e++){
        if(vector1[e] > vector2[e]){
            bandera = false;
            break;
        }
        operations += abs(vector1[e] - vector2[e]);
    }
    cout << (bandera ? operations : -1) << endl;
    return 0;
}