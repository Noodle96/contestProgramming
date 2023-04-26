#include <bits/stdc++.h>
using namespace std;
int main(){
    string loveA;
    cin>> loveA;
    int cont = 0;
    for(int e = 0 ; e < loveA.size(); e++){
        if(loveA[e] == 'a')cont++;
    }
    // cout << "size: " << loveA.size() << endl;
    // cout << "as: " << cont << endl;
    if(cont >= ((loveA.size()+1)/2) +1 ){
        cout << loveA.size() << endl;
        return 0;
    }
    cout <<  cont*2 -1 << endl;
    return 0;
}