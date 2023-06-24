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

string preprocessing(string &str){
	string result;
	for(int e = 0 ; e < str.size(); e++){
		if(str[e] == '.' or str[e] == ',' or str[e] == '!' or str[e] == '?' or str[e] == ' ') continue;
		else result += str[e];
	}
	for(int e = 0 ; e < result.size(); e++){
		result[e] = tolower(result[e]);
	}
	return result;
}
int main(){
	// int t; cin>>t;cin >> ws; 
	string line;
	// cin>>ws;
	while(getline(cin, line) && line != "DONE"){
		// string line;
		// cout << "line es: " << line <<endl;
		// std::cout << preprocessing(line) << endl;
		line = preprocessing(line);
		if(isPalindromo(line))cout << "You won't be eaten!" << endl;
		else cout << "Uh oh.."<< endl;
	}
	
	return 0;
}