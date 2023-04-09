#include <bits/stdc++.h>
using namespace std;
void printVector(string &vec){
    for(auto e = vec.begin() ;e!= vec.end() ; e++){
        cout << *e << " ";
    }
    cout << endl;
}
int main(){
    string s;
    getline(cin,s);
    string vec = "";
    for(auto e = 0 ; e < s.size() ; e++){
        if(s[e] != '+') vec += s[e];
    }
    sort(vec.begin(), vec.end());
    // cout << "vec: " << vec << endl;
    string result = "";
    for(int e = 0 ;e  < vec.size() -1 ; e++){
        result += vec[e];
        result +="+";
    }
    result += vec[vec.size()-1];
    cout << result << endl;
    return 0;
}