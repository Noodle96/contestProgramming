#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define msg(str,str2) cout << str << str2<< endl
using namespace std;
void solve(){
	string english, foreign,linea;
	map<string,string> mapa;
	std::getline(cin,linea);
	while(linea != ""){
		stringstream ss(linea);
		ss >> english >>foreign;
		mapa[foreign] = english;
		// msg("ingles: ", english);
		// msg("foreign: ", foreign);
		std::getline(cin,linea);
	}
	while(cin>>foreign){
		if(mapa.count(foreign) > 0)msg(mapa[foreign],"");
		else msg("eh","");
	}
}
int main(){
	// #ifndef IN_OUT
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
	
	solve();
	return 0;
}