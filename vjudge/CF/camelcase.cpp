#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define HERE cout << "i here" << endl;
using namespace std;
void solve(){
	string word;cin>> word;
	int cont  = 1;
	for(int e = 0 ; e < word.size(); e++){
		if(word[e] < 97) cont ++;
	}
	if(cont <= 7) cout << "YES" << endl;
	else cout << "NO" << endl;
}
int main(){
	int t; cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}