/*
==========================================================
|  Archivo       : accurateLee.cpp
|  Autor         : Russell
|  Fecha         : 2023-04-18 18:21
|--------------------------------------------------------
|  Tópicos utilizados:
|  - training
|  - *1200
|  - strings
|  - implementation
==========================================================
*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    int n; string s;
    int l,r;
    while(t--){
        cin>>n>>s;
        l = s.find('1');
        r = s.rfind('0');
        if(l!=-1 && r!= -1 && r>l) s.erase(l,r-l);
        cout << s << endl;
    }
    return 0;
}