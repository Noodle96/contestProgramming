#include <bits/stdc++.h>
using namespace std;
int f(string &s){
	char current = 'a';
	int count = 0;
	for(int e = 0 ; e < s.size() ; e++){
		if(current >= s[e]){
			count += min(current-s[e], 'z'-current + s[e] - 'a' +1);
		}else{
			count += min(s[e]-current, current-'a' + 'z' - s[e] +1);
		}
		current  = s[e];
	}
	return count;
}
int main(){
	string s; cin>>s;
	cout << f(s) << endl;
	return 0;
}