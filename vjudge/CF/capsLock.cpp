#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define HERE cout << "i here" << endl;
using namespace std;
bool allUpper(string str){
	for(int e = 0 ; e < str.size(); e++){
		if(str[e] > 95) return false;
	}
	return true;
}
string convertLower(string str){
	string str2 = "";
	for(int  e= 0 ;e < str.size() ; e++){
		str2 += tolower(str[e]);
	}
	// cout << "in function: " << str2 << endl;
	return str2;
}
void solve(){
	string str; cin>> str;
	string str_temp;
	if(allUpper(str)){
		str_temp = convertLower(str);
		cout << str_temp << endl;
	}else if(str[0] > 95 && allUpper(str.substr(1,str.size()-1))){
		// cout << "printing str: " << str << endl;
		str_temp = convertLower(str.substr(1, str.size()-1));
		// cout << "printing: " << str_temp << endl;
		string firstCaracter; firstCaracter = toupper(str[0]);
		cout << firstCaracter << str_temp << endl;
	}else{
		cout << str << endl;
	}
}
int main(){
	solve();
	return 0;
}