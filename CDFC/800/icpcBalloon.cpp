#include <bits/stdc++.h>
using namespace std;
int f(string &str, int n){
	unordered_map<char,int> hash;
	for(auto e = 0 ;e < n ; e++) hash[str[e]]++;
	return n + hash.size();
}
int main(){
	int t; cin>>t;
	int n; string str;
	while(t--){
		cin >> n;
		cin>> str;
		cout << f(str,n) << endl;
	}
	return 0;
}