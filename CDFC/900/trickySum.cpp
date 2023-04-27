#include <bits/stdc++.h>
using namespace std;
long long f(long long num){
    long long result = num*(num+1)/2;
    // cout << "result: " << result <<endl;
    long long power2 = log2(num) +1;
    // cout << "pw: " <<power2 << endl;
    power2 = pow(2,power2) -1;
    // cout << "pw: " <<power2 << endl;

    return result - 2*power2;
}
int main(){
    int t; cin>>t;
    long long temp;
    while(t--){
        cin>>temp;
        cout << f(temp) << endl;
    }

    // int num;
    // while(cin>>num){
    //     int resp = log2(num);
    //     cout <<  resp<< endl;

    // }

    
    return 0;
}