#include <bits/stdc++.h>
using namespace std;
int main(){
    short int n,count=0; cin>>n;
    string operacion;
    while(n--){
        cin>>operacion;
        if(operacion == "++X"  or operacion == "X++") count ++;
        else count --;
    }
    cout <<  count << endl;
    return 0;
}