#include <bits/stdc++.h>
using namespace std;
int main(){
    string adn;
    cin>> adn;
    map<char,int> frecuencias;
    for(auto e = 0  ; e< adn.size();e++){
        frecuencias[adn[e]]++;
    }
    int maximo = 0;
    for(auto e= frecuencias.begin(); e!= frecuencias.end(); e++){
        cout << e->first << "->" << e->second << endl;
        maximo = max(maximo,e->second);
    }
    cout << maximo;
    return 0;
}