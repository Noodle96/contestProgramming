#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define HERE cout << "i here" << endl;
using namespace std;
bool isPalindromo(string str){
	int n = str.size();
	for(int e = 0 ; e < n/2; e++){
		if(str[e] != str[n-e-1]) return false;
	}
	return true;
}
void solve(){
	string str; cin>>str;
	if(isPalindromo(str)){cout << 0 << endl; return;}
	int n = str.size();
	int cont  = 0 ;
	for(int e = 0 ; e < n/2; e++){
		if(str[e] !=  str[n-e-1]) cont ++;
	}
	cout << cont << endl;
}
int main(){
	solve();
	return 0;
}