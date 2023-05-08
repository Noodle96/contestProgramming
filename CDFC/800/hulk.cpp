#include <bits/stdc++.h>
using namespace std;
void feel(int n){
    for(int e = 0 ;e < n ; e++){
        if(e&1){cout << "I love";}
        else{cout << "I hate";}
        if(e != n-1 ) cout << " that ";
    }
    cout << " it" << endl;
}
int main(){
    int n; cin>>n;
    feel(n);
    return 0;
}