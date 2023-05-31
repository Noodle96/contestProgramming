#include <bits/stdc++.h>
using namespace std;
int f(int a, int b , int c){
	if(a-b < c) return c - (a-b);
	return 0;
}
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	cout <<  f(a,b,c)<< endl;
	return 0;
}