#include <bits/stdc++.h>
using namespace std;
void maxNumber(string &number, int n, int d, string &result){
    auto e = 0;
    int k = 0;
    for(;e < n ; e++){
        // cout << number[e] - '0'<< endl;
        if(!k){
            if(d >number[e]-'0'){
                result += to_string(d);
                k++;
            }
        }
        result += number[e];
    }
    if(!k){
        result += to_string(d);
    }
    
}
int main(){
    int t; cin>> t;
    int n,d;
    string number;
    while(t--){
        cin>>n>>d;
        cin>>number;
        string result;
        maxNumber(number,n,d,result);
        cout << result << endl;
    }
    return 0;
}