#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define HERE cout << "i here" << endl;
using namespace std;
void solve(){
	string str1, str2; cin>> str1>>str2;
	int n = str1.size();
	for(int e = 0 ; e < n ; e++){
		if(str1[e] != str2[n-1-e]){cout << "NO" << endl; return;}
	}
	cout << "YES" << endl;
}
int main(){
	solve();
	return 0;
}