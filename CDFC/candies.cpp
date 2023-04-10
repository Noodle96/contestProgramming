#include <bits/stdc++.h>
using namespace std;
int main(){
    int t ; cin>> t;
    long long n;
    while(t--){
        cin>>n;
        for(auto k = 2; true ; k++){
            long long exponencial = (pow(2,k) -1);
            if( n % exponencial == 0){
                cout << (n/exponencial)<< endl;
                break;
            }
        }
    }
    return 0;
}