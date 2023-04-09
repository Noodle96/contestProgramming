#include <bits/stdc++.h>
using namespace std;
int main(){
    int number;
    cin>>number;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Skip just past the end of the line
    string s;
    getline(cin,s);
    auto before = s.begin();
    auto current = ++s.begin();
    int count = 0;
    for( ; current != s.end() ; current++){
        if(*before == *current){
            count ++;
        }
        before = current;
    }
    cout << count << endl;
    return 0;
}