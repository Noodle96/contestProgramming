#include <bits/stdc++.h>
using namespace std;
int main(){
    float a,b,c,d;
    cin >>a>>b>>c>>d;
    cout << a*d /(b*c + a*d -a*c) << endl;
    return 0;
}