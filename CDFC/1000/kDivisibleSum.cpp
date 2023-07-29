
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
void solve(){
	ll n,k; cin>>n>>k;
	// if(n==k){cout << 1 << endl; return;}
	if(n==k){cout << 1 << endl; return;}
	if(n==1){cout << k << endl; return;}
	if(k==1) {cout << 1 << endl; return;}
	if(n<k){
		if(k%n==0){cout << k/n << endl; return;}
		else {cout << k/n +1 << endl; return;}
	}
	//k>n
	if(n%k==0){cout << 1 << endl;return;}
	k = k*(n/k +1);
	if(k%n==0){cout << k/n << endl; return;}
	else {cout << k/n +1 << endl; return;}
}
int main(){
	int t; cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}