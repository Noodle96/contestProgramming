#include <bits/stdc++.h>
using namespace std;
int main(){
    short int row=0, col = 0;
    bool temp;
    for(auto e = 0 ; e < 5 ; e++){
        for(auto j = 0 ;j < 5 ; j++){
            cin>>temp;
            if(temp){
                row = e+1;
                col = j+1;
            }
        }
    }
    cout << abs(3-row) + abs(3-col) << endl;
    return 0;
}