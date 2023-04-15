#include <bits/stdc++.h>
using namespace std;
int main(){
    string S;
    getline(cin,S);
    int positionk;
    vector<int> positionB;
    vector<int> positionR;
    for(auto e = 0 ; e < S.size() ;e++){
        if(S[e] == 'K'){
            positionk = e+1;
        }
        if(S[e] == 'R'){
            positionR.push_back(e+1);
        }
        if(S[e] == 'B'){
            positionB.push_back(e+1);
        }
    }
    auto first = positionB.begin();
    auto second = ++positionB.begin();
    // cout << positionk << endl;
    // cout  << *first << endl;
    // cout << *second << endl;
    if( (*first + *second)%2==0){
        cout << "No"<< endl;
        return 0;
    }
    auto firstR = positionR.begin();
    auto secondR = ++positionR.begin();
    if((positionk <= *firstR) || (positionk >= *secondR)){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}