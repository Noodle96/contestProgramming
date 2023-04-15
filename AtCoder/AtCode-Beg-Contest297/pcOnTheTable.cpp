#include <bits/stdc++.h>
using namespace std;
int main(){
    int H,W; cin>>H>>W;
    vector<string> vec;
    string temp;
    while(H--){
        cin>>temp;
        vec.push_back(temp);
    }
    // for(auto it = vec.begin(); it != vec.end() ; it++){
    //     cout << *it << endl;
    // }
    for(int e = 0 ;e < vec.size() ; e++){
        for(auto j = 0 ;j < W-1 ; j++){
            if(vec[e][j] == 'T' && (vec[e][j] == vec[e][j+1])){
                vec[e][j] = 'P';
                vec[e][j+1] = 'C';
            }
        }
        cout << vec[e] << endl;
    }
    return 0;
}