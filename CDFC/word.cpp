#include <bits/stdc++.h>
using namespace std;

void convertWord(string &str, bool lower){
    if(lower){
        for(auto e = 0 ; e < str.size(); e++){
            str[e] = tolower(str[e]);
        }
    }else{
        for(auto e = 0 ; e < str.size(); e++){
            str[e] = toupper(str[e]);
        }
    }
}

int main(){
    string word; getline(cin,word);
    auto lower = 0;
    for(auto it = word.begin() ; it != word.end(); it++){
        if( islower(*it) ){
            lower++;
        }
    }
    if((lower > word.size() -lower ) || (lower == word.size()-lower)){
        convertWord(word,1);
    }else{
        convertWord(word,0);
    }
    cout << word << endl;
    return 0;
}