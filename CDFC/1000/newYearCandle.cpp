#include <bits/stdc++.h>
using namespace std;
int f(int &a, int &b){
    int cont = a;
    int restante = 0;
    while(a>=b){
        restante = a%b;
        a /=b;
        cont += a;
        a += restante;
    }
    return cont;

}
int main(){
    int a,b; cin>>a>>b;
    cout << f(a,b) << endl;
    return 0;
}