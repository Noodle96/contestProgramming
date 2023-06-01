#include <bits/stdc++.h>
using namespace std;
bool f(int a, int b, int c){
	if(a == b+c) return true;
	if(b == a+c) return true;
	if(c == a+b) return true;
	return false;
}
int main(){
	int t; cin>>t;
	int a,b,c;
	while(t--){
		cin>>a>>b>>c;
		cout << (f(a,b,c) ? "YES":"NO") << endl;
	}
	return 0;
}