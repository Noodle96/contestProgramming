#include <bits/stdc++.h>
using namespace std;
// Function to print the divisors
int_least16_t printDivisors(int n){
	int cont=0;
	for (int i=1; i<=sqrt(n); i++){
		if (n%i == 0){
			// If divisors are equal, print only one
			if (n/i == i) cont++;
				// cout <<" "<< i;
			else cont +=2; // Otherwise print both
				// cout << " "<< i << " " << n/i;
		}
	}
	return cont;
}
int main(){
	int t; cin>>t;
	int n;
	while(t--){
		cin>>n;
		cout << printDivisors(n) << endl;
	}
	return 0;
}

