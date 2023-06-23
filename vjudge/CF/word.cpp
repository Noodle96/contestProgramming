#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define HERE cout << "i here" << endl;
using namespace std;
void solve(){
	string str; cin>> str;
	int n = str.size();
	int contUppercase = 0;
	string uppercase, lowercase;
	for(int e = 0; e < n; e++ ){
		if(str[e] < 97){ //mayusculas
			contUppercase++;
		}
		uppercase += toupper(str[e]);
		lowercase += tolower(str[e]);
	}
	int contLowercase = n-contUppercase;
	if(contLowercase >= contUppercase) cout << lowercase << endl;
	else cout << uppercase << endl;
}
int main(){
	solve();
	return 0;
}