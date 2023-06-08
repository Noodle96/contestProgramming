#include <bits/stdc++.h>
using namespace std;
int generate(int n){
	int count = 1;
	for(int e = 1 ; e < n ; e++){
		count += pow(10,e);
	}
	return count;
}
int digitos(int n){
	int cont = 0;
	while(n){
		cont++;
		n /=10;
	}
	return cont;
}
int solve(){
	int n; cin>>n;
	if(n == 10) return 9;
	if(n <= 9) return n;
	int cont = 0;
	int  nCopy = n;
	if(!(n%10)) n -=1;
	while(n){
		cont++;
		n /= 10;
	}
	// nCopy = nCopy - pow(10, cont-1);
	return (9*(cont-1) + nCopy / generate(digitos(nCopy-1)));
}
int main(){
	int t; cin>>t;
	while(t--){
		cout << solve() << endl;
		// int n; cin>>n;
		// cout << generate(n) << endl;
		// cout << digitos(n) << endl;

	}

	return 0;
}