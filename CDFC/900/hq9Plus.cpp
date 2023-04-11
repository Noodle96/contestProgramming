#include <bits/stdc++.h>
using namespace std;
int main(){
    string p; getline(cin,p);
    for(auto e = p.begin(); e!= p.end(); e++){
        if(*e == 'H' or *e=='Q' or *e == '9' ){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}