#include <bits/stdc++.h>
using namespace std;
void printVector(vector<long long> &vec){
    for(auto e = vec.begin() ; e != vec.end(); e++){
        cout <<*e << " ";
    }
    cout << endl;
}
int main(){
    int t; cin>> t;
    int n;
    long long temp;
    vector<long long> vec;
    while(t--){
        cin>>n;
        while(n--){
            cin>>temp;
            vec.push_back(temp);
        }
        vector<long long > vec2(vec.begin(), vec.end());
        //sorting the second vector
        sort(vec2.begin(), vec2.end(), greater<int>());
        // printVector(vec);
        // printVector(vec2);
        auto first = vec2.begin();
        auto second = ++vec2.begin();
        // cout << *first <<endl;
        // cout << *second <<endl;
        //recorrer el areglo original
        for(auto it = vec.begin() ;it != vec.end() ; it++){
            cout << (*it != *first ? (*it - *first) : (*it - *second)) << endl;
        }
        vec.clear();
        vec2.clear();
    }
    return 0;
}