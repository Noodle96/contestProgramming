#include <bits/stdc++.h>
using namespace std;
int main(){
	string str1, str2, str3;
	cin>>str1>>str2>>str3;
	map<char,int> mapInicio;
	map<char,int> mapFinal;

	for(int e = 0 ;e < str1.size() ; e++) mapInicio[str1[e]]++;
	for(int e = 0 ;e < str2.size() ; e++) mapInicio[str2[e]]++;
	for(int e = 0 ;e < str3.size() ; e++) mapFinal[str3[e]]++;

	//MAPS FILLS
	auto it = mapInicio.begin();
	auto et = mapFinal.begin(); 


	// cout <<"first" << endl;
	// for(auto it = mapInicio.begin(); it != mapInicio.end() ; it++){
	// 	cout << it->first << " : " << it->second << endl;
	// }
	// cout <<"second" << endl;
	// for(auto it = mapFinal.begin(); it != mapFinal.end() ; it++){
	// 	cout << it->first << " : " << it->second << endl;
	// }

	if(mapInicio.size() != mapFinal.size()){cout << "NO" << endl; return 0;}
	for( ; it != mapInicio.end() ; it++, et++){
		if(it->first != et->first || it->second != et->second){
			cout << "NO" << endl;return 0;
		}
	}
	cout << "YES" << endl;

	return 0;
}