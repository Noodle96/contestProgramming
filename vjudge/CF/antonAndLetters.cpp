#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define HERE cout << "i here" << endl;
using namespace std;
void solve(){
	string cadena; getline(cin,cadena);
	map<char,int> map;
	for(int e = cadena.size() -2 ; e > 0 ; e-=3){
		// cout << cadena[e] << endl;
		map[cadena[e]]++;
	}
	cout <<map.size() <<  endl;
}
int main(){
	solve();
	return 0;
}