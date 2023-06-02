#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(√n)
// Auxiliary Space: O(1)
bool isPrime(int n){
	if (n == 2 || n == 3)
		return true;

	if (n <= 1 || n % 2 == 0 || n % 3 == 0)
		return false;

	// To check through all numbers of the form 6k ± 1
	for (int i = 5; i * i <= n; i += 6) {
		if (n % i == 0 || n % (i + 2) == 0)
			return false;
	}
	return true;
}
void solve(){
	int n; cin>>n;
	for(int m = 1 ; m < 1000 ;m++){
		if(!isPrime(n*m+1)){cout << m << endl; return;}
	}

}

int main(){
	solve();
	return 0;
}