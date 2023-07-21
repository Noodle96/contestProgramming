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
void solve(){
	ll n;
	ll k;
	cin>>n>>k;
	vector<ll> vec(n);
	for(ll &e:vec )cin>>e;
	if(n == 1){cout << 0 << endl; return;}
	
	sort(all(vec));
	ll maximo = LONG_MIN;
	ll len = 1;
	for(int e = 0 ;e < n-1 ; e++){
		if( abs(vec[e] - vec[e+1]) <= k ){
			len++;
			maximo = max(len, maximo);
		}else{
			len = 1;
		}
	}
	maximo = max(len,maximo);
	// cout << "n: " << n << " maximo: " << maximo << endl;
	cout << n-maximo<< endl;
}
int main(){
	// #ifndef IN_OUT
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
	
	int t; cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}