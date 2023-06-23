#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define HERE cout << "i here" << endl;
using namespace std;
void solve(){
	int n; cin>>n;
	string str1, str2,str3; cin>>str1>>str2;
	for(int e = 0; e < n;e++){
		str3 += str1[e];
		str3 += str2[e];
	}
	cout << str3 << endl;
}
int main(){
	solve();
	return 0;
}