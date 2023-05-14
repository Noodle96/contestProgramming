#include <bits/stdc++.h>
using namespace std;
// bool isDivisibleArray(vector<int> &vec, int n){
//     int suma =  accumulate(vec.begin(), vec.end(), 0);
//     return suma == 
// }
void f(int n){
    vector<int> vec(n);
    for(int e = 0 ;e < n ; e++) vec[e] = e+1;
    int suma = n*(n+1)/2;
    int rsto = suma % n;
    for(int e = 0 ; e < n; e++){
        if(e == rsto -1) cout << vec[e]*2 << " ";
        else cout << vec[e] << " ";
    }cout << endl;

}

int main(){
    int t; cin>>t;
    int n;
    while(t--){
        cin>>n;
        f(n);
    }
    return 0;
}