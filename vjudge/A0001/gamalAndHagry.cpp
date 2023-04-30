#include <bits/stdc++.h>
using namespace std;
bool isDecimal(float f){ //10.3
    int i = f; //i = 10
    if(f-i) return true; //10.3 -10 = 0.3
    return false;
}
long long f(long long k){
    float rq;
    for(int e = 191 ; true ;e++){
        rq = pow((111 + 125*e),1.0/3.0);
        if(!isDecimal(rq)){
            if(2*rq > k) return 2*rq;
        }
    }
    return -1;
}
int main(){
    int t;cin>>t;
    long long k;
    // while(t--){
    //     cin>>k;
    //     cout << f(k) << endl;
    // } 
    int j = 0;
    while(j < 10){
        cout << f(j) << endl;
        j++;
    }   
    return 0;
}