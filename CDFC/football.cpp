#include <bits/stdc++.h>
using namespace std;
int main(){
    string situation;
    getline(cin,situation);
    auto before = situation.begin();
    auto current = ++situation.begin();
    int cont = 1;
    int maximo = 0;
    for( ; current != situation.end(); current++){
        if(*before == *current){
            cont++;
            maximo = max(cont,maximo);
        }else{
            cont = 1;
        }
        before = current;
    }
    cout << (maximo >= 7 ? "YES" : "NO") << endl;
    return 0;
}