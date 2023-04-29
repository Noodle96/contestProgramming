#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> lista(4);
    for(int e = 0 ; e < 4; e++) cin>>lista[e];
    auto maximo = max_element(lista.begin(), lista.end());
    for(int e = 0 ; e < 4 ; e++){
        if(*maximo - lista[e] != 0)cout << (*maximo - lista[e]) << " ";
    }cout << endl;
    return 0;
}