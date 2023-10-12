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

bool isPrime(int n){
	if (n == 2 || n == 3) return true;
	if (n <= 1 || n % 2 == 0 || n % 3 == 0) return false;
	// To check through all numbers of the form 6k ± 1
	for (int i = 5; i * i <= n; i += 6){
		if (n % i == 0 || n % (i + 2) == 0) return false;
	}
	return true;
}

void solve(){
	int n; cin>>n;
	if(n == 2) cout << 2 << endl;
	else cout << 3 << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}