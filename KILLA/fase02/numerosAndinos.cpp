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

int gcd(int a,int b){
	if(a%b==0) return b;
	else return gcd(b,a%b);
}

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
ll cont = 0;
ll power;
map<ll,ll> mapa;

bool isPrime(ll n){
	if (n == 2 || n == 3) return true;
	if (n <= 1 || n % 2 == 0 || n % 3 == 0) return false;
	// To check through all numbers of the form 6k ± 1
	for (ll i = 5; i * i <= n; i += 6) {
		if (n % i == 0 || n % (i + 2) == 0)
			return false;
	}
	return true;
}

void solve(){
	ll n; cin>>n;
	// ll e = 2;
	// power = e;
	// while(n % power  == 0){
	// 	cout << "n: " << n  << " power: "<< power<< endl;
	// 	mapa[power]++;
	// 	n /= power;
	// 	power *= e;
	// 	cont++;
	// }

	// e = 3;
	// for(; e*e <= n; e+=2){
	// 	if(n % e == 0){
	// 		power = e;
	// 		while(n%power == 0 && mapa.count(power) == 0 ){
	// 			cout << "n: " << n  << " power: "<< power<< endl;
	// 			mapa[power]++;
	// 			n /= power;
	// 			power *= e;
	// 			cont++;
	// 		}
	// 	}
	// }
	// cout << "final n: " << n  << endl;
	// if(n > 1){
	// 	if( mapa.count(n)  > 0 || !isPrime(n)){;}
	// 	else cont++;
	// }
	// cout << cont << endl;
	ll n_copy = n;
	ll i = 2;
	for( ;i*i <= n ; i++){
		if(n % i == 0){
			ll e = 0 ;
			while(n % i == 0){
				e++;
				n /= i;
			}
			mapa[i] = e;
		}
	}
	if(n>1){
		mapa[n] = 1;
	}
	ll cont = 0 ;
	for(auto it = mapa.begin(); it != mapa.end() ; it++){
		ll pow = it->first;
		while(n_copy % pow == 0){
			n_copy /=pow;
			pow *= it->first;
			cont ++;
		}
	}
	cout << cont << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}

//8 = 1 2 4 8