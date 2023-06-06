#include <bits/stdc++.h>
using namespace std;
void solve(){
	int n; string str;
	cin>>n;
	cin>>str;
	string rpta;
	auto pivote = str[0];
	rpta += pivote;
	for(int e = 1; e < n-1; e++){
		if(pivote == str[e]){
			rpta += str[e+1];
			pivote = str[e+1]; e++;
		}
	}
	cout << rpta << endl;
}
int main(){
	int t; cin>>t;
	while(t--){
		solve();
	}
	return 0;
}