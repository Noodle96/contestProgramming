#include<bits/stdc++.h>
using namespace std;
int distanceAB_(char a, char b){
	a-=96;
	b-=96;
	if(b>=a) return b-a;
	else return 26-a + b - 0;
}
bool f(string &str1, string &str2){
	auto distance = distanceAB_(str1[0], str2[0]);
	for(int e = 1 ;e < str1.size() ; e++){
		if(distanceAB_(str1[e],str2[e])!= distance) return false;
	}
	return true;
}
int main(){
	string a,b;
	cin>>a>>b;
	cout << (f(a,b)?"Yes":"No") << endl;
	// char a; cin>>a; char b; cin>>b;
	// cout << (distanceAB_(a,b) ?"Yes": "No") << endl;

	return 0;
}