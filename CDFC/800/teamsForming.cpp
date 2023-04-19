#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int> skills;
    int temp;
    while(n--){
        cin>>temp;
        skills.push_back(temp);
    }
    sort(skills.begin(), skills.end());
    // for(auto it = skills.begin(); it != skills.end() ; it++){
    //     cout << *it << endl;
    // }
    int cont = 0;
    for(auto e = 0 ;e < skills.size() -1 ;e+=2){
        cont += (skills[e+1] - skills[e] );
    }
    cout << cont << endl;
    return 0;
}