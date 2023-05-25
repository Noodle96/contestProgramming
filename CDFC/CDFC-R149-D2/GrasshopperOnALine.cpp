#include <bits/stdc++.h>
using namespace std;
bool isDivisibleByN(int n1, int n2, int number){
    if(( n1 % number == 0) && ( n2 % number == 0)) return true;
    return false;
}

void f(int x, int k){
    if(x % k != 0){
        cout << 1 << endl;
        cout << x << endl;
        return;
    }else{
        for(int e = 1; e <= x; e++){
            if( !isDivisibleByN( e, x-e,k) ){
                cout << 2 << endl;
                cout << e << " " << x-e << endl;
                return;
            }
        }
    }
}
int main(){
    int t; cin>>t;
    int x,k;
    while(t--){
        cin>>x>>k;
        f(x,k);
    }

    // for(int e = 0 ;e < 10 ; e++){
    //     cout << "e: " << e << " -> " << isDivisibleByN(e,2) << endl;
    // }

    return 0;
}