#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int> vec(n);
    vector<int> vecCopy(n);
    for(int e = 0 ;e < n ; e++){
        cin>> vec[e];
        vecCopy[e] = vec[e];
    }
    sort(vecCopy.begin(), vecCopy.end());
    float swapping = 0;
    for(auto e = 0 ; e < n ; e++){
        if(vec[e] != vecCopy[e]){
            swapping++;
        }
    }
    swapping= ceil(swapping/2);
    cout << (swapping >=2 ? "NO":"YES")<< endl;
    return 0;
}