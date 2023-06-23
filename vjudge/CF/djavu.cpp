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
bool allA(string  &str){
	for(int e = 0 ; e < str.size(); e++){
		if(str[e] != 'a') return false;
	}
	return true;
}
void solve(){
	string str; cin>>str;
	if(allA(str)){
		cout << "NO" << endl; return;
	}
	if(isPalindromo(str)){
		cout << "YES" << endl;
		cout << "a" << str << endl;
	}else{
		cout << "YES" << endl;
		if(str[0] == 'a'){
			if(isPalindromo("a"+str)){
				cout  << str << "a"<< endl;
			}else{
				cout << "a" << str << endl;
			}
		}else{
			if(isPalindromo(str+"a")){
				cout << "a" << str << endl;
			}else{
				cout  << str << "a"<< endl;
			}
		}
	}
	
}
int main(){
	// #ifndef IN_OUT
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
	
	int t;cin>>t;
	string str;
	while(t--){
		solve();
	}
	
	return 0;
}