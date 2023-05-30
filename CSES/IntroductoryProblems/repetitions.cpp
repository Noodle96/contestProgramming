#include <bits/stdc++.h>
using namespace std;
using T = int;
int main(){
    string adn;
    cin>> adn;
    auto before = adn[0];
    auto current = adn[0];
    T maximo = 1;
    T maximo_temp = 1;
    for(auto e = 1 ; e != adn.size(); e++){
        current = adn[e];
        if(before == current){
            maximo_temp ++;
            maximo = max(maximo,maximo_temp);
        }else{
            maximo_temp = 1;
            maximo = max(maximo,maximo_temp);
        }
        before = current;
    }
    cout << maximo << endl;
    return 0;
}