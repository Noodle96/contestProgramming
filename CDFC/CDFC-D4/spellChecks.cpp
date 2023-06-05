#include <bits/stdc++.h>
using namespace std;
bool f(string &str, int n){
	if(n != 5) return false;
	string name = "Timur";

	sort(name.begin(), name.end());
	do{
		if(name == str) return true;
	}while(next_permutation(name.begin(), name.end()));
	return false;
}
int main(){
	int t; cin>>t;
	int n;
	string s;
	while(t--){
		cin>>n;
		cin>>s;
		cout << (f(s,n)? "YES":"NO") << endl;
	}
	return 0;
}