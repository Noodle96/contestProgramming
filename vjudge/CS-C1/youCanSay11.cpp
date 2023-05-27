#include <bits/stdc++.h>
using namespace std;
bool isMultiple11ValidType(long long number){
	return number%11==0;
}
bool multiple11(string &number){
	long long cont = 0 ;
	for(int e = 0 ;e < number.size() ; e++){
		if(e&1) cont -= (number[e] - '0');
		else cont += (number[e] - '0');
	}
	return isMultiple11ValidType(cont);
}
int main(){
	string aaa;
	while(true){
		cin>> aaa;
		if(aaa == "0") break;
		if(multiple11(aaa)){
			cout << aaa + " is a multiple of 11." << endl;
		}else{
			cout << aaa + " is not a multiple of 11." << endl;
		} 	
	}
	return 0;
}