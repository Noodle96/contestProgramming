#include <bits/stdc++.h>
using namespace std;
void f(string &str){
	string rpta;
	for(auto e = 0 ;e < str.size() ; e++){
		if(str[e] == '.') rpta += to_string(0);
		if(str[e] == '-'){
			if(str[e+1] == '.') rpta += to_string(1);
			else rpta += to_string(2);
			e++;
		}
	}
	cout << rpta << endl;
}
int main(){
	string str; cin>> str;
	f(str);
	return 0;
}