#include <bits/stdc++.h>
using namespace std;

bool f(int n, string &str1, string &str2){
	for(int e = 0 ; e < n; e++){
		if(str1[e] != str2[e]){
			if(str1[e] == 'R' or str2[e] == 'R') return false;
		}
	}
	return true;
}
int main(){
	int t; cin>>t;
	int n;
	string first;
	string second;
	while(t--){
		cin>>n; cin>> first; cin>> second;
		cout << (f(n,first,second)?"YES":"NO") << endl;
	}
	return 0;
}