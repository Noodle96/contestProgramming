#include <bits/stdc++.h>
using namespace std;
int f(string &str){
	auto first = str[0];
	auto last = str[2];
	return (first - '0') * (last - '0');

}
int main(){
	//test since CP editor
	string S; cin>>S;
	cout << f(S) << endl;
	return 0;
}