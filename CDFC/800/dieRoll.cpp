#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b; // 4 2
	cin >> a >> b ;
	a = 6 - max(a,b) + 1 ;  //3
	b=__gcd(6,a); //3
	cout<<(a/b)<<"/"<<(6/b)<<endl;
}