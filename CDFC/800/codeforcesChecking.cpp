#include <bits/stdc++.h>
using namespace std;
string codeforces = "codeforces";
bool f(char &c){
	auto it = codeforces.find(c);
	return it != string::npos;
}
int main(){
	int t; cin>>t;
	char c;
	while(t--){
		cin>>c;
		cout << (f(c) ? "yEs" : "nO") << endl;
	}
	return 0;
}