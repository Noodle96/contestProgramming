/*
==========================================================
|  Archivo       : archer.cpp
|  Autor         : Russell
|  Fecha         : 2023-05-04 17:09
|--------------------------------------------------------
|  Tópicos utilizados:
|  - training
|  - *1300
|  - math
|  - probabilities
==========================================================
*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    float a,b,c,d;
    cin >>a>>b>>c>>d;
    cout << a*d /(b*c + a*d -a*c) << endl;
    return 0;
}