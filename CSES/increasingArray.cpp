#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<long long> vec;
    long long temp;
    while(n--){
        cin>>temp;
        vec.push_back(temp);
    }
    auto before = vec.begin();
    auto current = ++vec.begin();
    long long pasos = 0;
    for(;current != vec.end() ; current++){
        if(*current < *before){
            pasos += (*before - *current);
            *current = *before;
        }
        before = current;
    }
    cout << pasos << endl;
    // cout << "pasos: " << pasos << endl;
    // cout << "printing vec" << endl;
    // for(auto it = vec.begin() ;it != vec.end() ; it++){
    //     cout << *it << " ";
    // }
    // cout << endl;

    return 0;
}