#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define HERE cout << "i here" << endl;
using namespace std;
void solve(){
	string str1,str2; cin>>str1>>str2;
	for(int e = 0; e < str1.size();e++) str1[e] = tolower(str1[e]);
	for(int e = 0; e < str2.size();e++) str2[e] = tolower(str2[e]);
	if(str1 == str2)cout << 0 <<endl;
	else if(str1 < str2) {cout << -1 << endl;}
	else {cout << 1 << endl;}
}
int main(){
	#ifndef IN_OUT
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	// int t;cin>>t;
	// while(t--){
	// 	solve();
	// }
	solve();
	
	return 0;
}