#include <bits/stdc++.h>
using namespace std;
int f(vector<int> &vec){
    sort(vec.begin(), vec.end());
    auto first = *vec.begin();
    int cont = 0;
    for(int e = 1 ; e < vec.size(); e++){
        cont += (vec[e] - first);
    }
    return cont;
}
int main(){
    int t; cin>>t;
    int n;
    vector<int> vec;
    while(t--){
        cin>>n;vec.resize(n);
        for(int e = 0 ;e < n ; e++) cin >>vec[e];
        cout << f(vec) << endl;
        vec.clear();
    }
    return 0;
}