#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    long long temp;
    vector<long long> vec;
    while(n--){
        cin>>temp;
        vec.push_back(temp);
    }
    long long sum = INT_MIN;
    long long particular = 0;

    //O(n^2)
    // for (size_t i = 0; i < vec.size(); i++){
    //     particular = vec[i];
    //     for (size_t j = i+1; j < vec.size(); j++){
    //         if(particular + vec[j] > sum){
    //             sum = particular + vec[j];
    //             particular = sum;
    //         }else{
    //             particular = particular +  vec[j];
    //         }
    //     }
    // }

    //O(n);
    for(auto e = 0; e < vec.size(); e++){
        particular += vec[e];
        if(particular > sum)
            sum = particular;
        if(particular<0)
            particular = 0;
    }
    cout << sum << endl;
    return 0;
}