#include<bits/stdc++.h>
using namespace std;
bool verifySound(string str){
    string sound = "";
    auto previous = str.begin();
    auto current = ++str.begin();
    // cout  << *previous << endl;
    // cout << *current << endl;
    
    for(; current != str.end() ; current++){
        if(*previous != *current){
            sound += *previous;
        }
        previous = current;
    }
    //add the last character
    sound += *previous;
    // cout << sound << endl;
    return "MEOW" == sound;
}


int main(){
    int t,n;
    char ch;
    string word = "";
    cin>> t;
    for (size_t i = 0; i < t; i++){
        cin >> n;
        word = "";
        for(auto e = 0 ; e < n; e++){
            cin>>ch;
            word += ch;
        }
        // cout << "la palabra es: " <<word << endl;
        transform(word.begin(), word.end(), word.begin(), ::toupper);
        // if(verifySound(word)){
        //     cout << "YES" << endl;
        // }else{
        //     cout << "NO" << endl;
        // }
        cout << ((verifySound(word)) ? "YES" : "NO") << endl;

    }
    return 0;
}

