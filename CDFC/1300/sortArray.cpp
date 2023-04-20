#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> vec(n);
    vector<int> vecTemp(n);
    for(int e = 0 ; e < n; e++){
        cin>>vec[e];
        vecTemp[e] = vec[e];
    }
    sort(vecTemp.begin(), vecTemp.end());
    // for(auto it = vecTemp.begin(); it != vecTemp.end() ; it++){
    //     cout << *it << endl;
    // }
    int left = 0,right = 0,k = 0;
    for(int e = 0 ; e < n; e++){
        if(vec[e] != vecTemp[e]){
            right = e; k++;
            if(k==1) left = e;
        }
    }
    reverse(vec.begin() + left, vec.begin() + 1 + right);
    for (auto e = 0; e < n  ; e++){
        if(vec[e]!= vecTemp[e]){
            cout << "no" << endl; return 0;
        }
    }
    cout << "yes" << endl;
    cout << left +1 << " " << right +1 << endl;
    return 0;
}