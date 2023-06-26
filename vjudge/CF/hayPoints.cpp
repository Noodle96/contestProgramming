#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define msg(str,str2) cout << str << str2<< endl
using namespace std;
void solve(){
	map<string,int> costos;
	int m,n; cin>>m>>n;
	string word; int costo;
	while(m--){
		cin>>word>>costo;
		costos[word]= costo;
	}
	// //leer la descripcion de cada trabajo
	string line,WORD;
	cin.ignore(); // if use getline() use this "cin.ignore();" after use cin>>int
	while(n--){
		getline(std::cin,line);
		int total = 0;
		while(line != "."){
			stringstream ss(line);
			while(ss>>WORD){
				if(costos.count(WORD) > 0) total += costos[WORD];
			}
			getline(std::cin,line);
		}
		msg(total,"");
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