#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int t; cin>> t;
    LL n,a;
    while(t--){
        cin>>n; a = 0;
        while(n%6==0){n/=6;a++;}
		while(n%3==0){n/=3;a+=2;}
		if(n!=1)a=-1;cout<<a<<endl;
    }
    return 0;
}