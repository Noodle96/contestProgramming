#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define msg(str,str2) cout << str << str2<< endl
using namespace std;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

#define pb push_back
#define mp make_pair
#define fi first
#define se second


void SieveOfEratosthenes(int n,int a,int b){
	// Create a boolean array "prime[0..n]" and initialize
	// all entries it as true. A value in prime[i] will
	// finally be false if i is Not a prime, else true.
	bool prime[n + 1];
	memset(prime, true, sizeof(prime));

	for (int p = 2; p * p <= n; p++) {
		// If prime[p] is not changed, then it is a prime
		if (prime[p] == true) {
			// Update all multiples of p greater than or
			// equal to the square of it numbers which are
			// multiple of p and are less than p^2 are
			// already been marked.
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}


	// Print all prime numbers
	// for (int p = 2; p <= n; p++)
	// 	if (prime[p])
	// 		cout << p << " ";
	vector<int> primes;
	for(int p =2 ; p <=50; p++){
		if(prime[p]) primes.pb(p);
	}
	for(int e = 0 ; e < 50; e++){
		if(primes[e] == a){
			if(primes[e+1] == b){
				cout << "YES" << endl;return;
			}else {cout << "NO" << endl; return;}
		}
	}


}

void solve(){
	int n,m; cin>>n>>m;
	SieveOfEratosthenes(50,n,m);


}
int main(){
	solve();
	return 0;
}