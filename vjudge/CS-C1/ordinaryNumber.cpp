#include <bits/stdc++.h>
using namespace std;
bool evaluate(int a, int b, int c){
    if(a > b){
        return b > c;
    }else if(c > b){
        //b < c
        return b > a;
    }
    return false;
}
int f(vector<int> &vec, int n){
    bool flag;
    int cont = 0;
    for(int e = 1; e < n-1;e++){
        flag = evaluate(vec[e-1], vec[e], vec[e+1]);
        if(flag) cont ++;
    }
    return cont;
}

int main(){
    int n; cin>>n; vector<int> vec(n);
    for(int&e:vec) cin>>e;
    cout << f(vec,n) << endl;
    return  0;
}