#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define msg(str, str2) cout << str << str2<< endl
using namespace std;

void solve(){
	// #ifndef IN_OUT
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
	
	string line, line_cpy;
	map< string, vector<string> > mapa;
	while(cin>>line && line != "XXXXXX"){
		line_cpy = line;
		sort(all(line));
		mapa[line].push_back(line_cpy);
	}

	//ordenar las listas de la matriz esparsa
	for(auto it = mapa.begin(); it != mapa.end() ; it++){
		sort(all(it->second));
	}

	//read las palabras revueltas
	while(cin>>line && line != "XXXXXX"){
		sort(all(line));
		if(mapa.count(line) > 0){ // verify si elelemento esta el mapa
			for(auto it = mapa[line].begin(); it != mapa[line].end() ; it++){
				msg(*it,"");
			}
		}else{ // no esta en el mapa
			msg("NOT A VALID WORD", "");
		}
		msg("******","");
	}
}
int main(){
	solve();
	return 0;
}