#include <bits/stdc++.h>
using namespace std;
bool isVowel(char c){
    if(isupper(c)) c = tolower(c);
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')return true;
    return false;
}

int main(){
    string word;getline(cin,word);
    string result = "";
    auto it = word.begin();
    while(it != word.end()){
        if(!isVowel(*it)){
            if(isupper(*it)){
                *it = tolower(*it);
            }
            result+='.';
            result += *it;
        }
        it++;
    }
    cout << result << endl;
    return 0;
}