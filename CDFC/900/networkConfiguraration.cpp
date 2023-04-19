#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k; cin>>n>>k;
    vector<int> speeds;
    int temp;
    while(n--){
        cin>>temp;
        speeds.push_back(temp);
    }
    sort(speeds.begin(),  speeds.end(), greater<int>());
    // for(auto it = speeds.begin(); it != speeds.end() ; it++){
    //     cout << *it << endl;
    // }
    cout << speeds[k-1] << endl;
    return 0;
}