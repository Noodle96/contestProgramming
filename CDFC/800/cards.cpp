#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    string str; cin>>str;
    int contN  = 0;
    for(int e = 0 ; e < n ;e++){
        if(str[e] == 'n') contN++;
    }
    // cout << "contN: " << contN << endl;
    int contZero = (n-contN*3)/4;
    // cout << "coutZ: " << contZero << endl;
    for(int e = 0 ; e < contN; e++) cout << 1 << " ";
    for(int e = 0 ; e < contZero; e++) cout << 0 <<" ";
    cout << endl;
    return 0;
}