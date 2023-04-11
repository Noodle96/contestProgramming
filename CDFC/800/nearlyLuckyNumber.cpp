#include <bits/stdc++.h>
using namespace std;

int main(){
    string number; getline(cin,number);
    long long cont = 0;
    for(auto e = 0; e < number.size(); e++){
        // cout << (number[e] != c) << endl;
        // cout << (number[e] != d) << endl;
        if((number[e] == '4') or (number[e] == '7')){
            cont++;
        }
    }
    // for(int e = 0 ;e < vec.size() ; e++){
    //     cout << vec[e] << " ";
    // }
    // cout << endl;
    cout << ( (cont == 7 or cont == 4)  ? "YES" : "NO") << endl;
    return 0;
}