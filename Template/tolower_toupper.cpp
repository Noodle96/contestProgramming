#include <bits/stdc++.h>
using namespace std;
int main(){
    string array1,array2;
    getline(cin,array1);
    // getline(cin,array2);
    //form 1
    for(auto e = 0 ; e < array1.size() ; e++){
        array1[e] = toupper(array1[e]);
    }
    cout << array1 << endl;

    //form 2
    // for(auto e = array1.begin(); e != array1.end(); e++){
    //     *e = toupper(*e);
    // }
    // cout << array1 << endl;

    

    //form 3
    // int i=0;
    // char str[]="Test String.\n";
    // char c;
    // string resultado = "";
    // while (str[i])
    // {
    //     c=str[i];
    //     putchar (toupper(c));
    //     i++;
    //     resultado += tolower(c);
    // }
    // cout << str << endl;
    // cout << resultado <<endl;


    return 0;
}