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
void solve(){
	int n; cin>>n;

	vector<ll> divisores;
	for(ll i =1 ;i*i <= n ; i++){
		if(n%i == 0){
			if(n/i == i) divisores.pb(i);
			else{
				divisores.pb(i); divisores.pb(n/i);
			}
		}
	}
	sort(all(divisores));
	// cout << divisores.size() << endl;
	// for(auto it = divisores.begin(); it != divisores.end() ; it++){
	// 	cout << *it << " ";
	// }cout << endl;
	// return;

	vector<ll> ans;
	vector<ll> vec(n);
	ll MAX = LLONG_MIN;
	ll MIN = LLONG_MAX;
	for(int e = 0 ; e < n; e++){
		cin>>vec[e];
		MAX = max(MAX,vec[e]);
		MIN = min(MIN, vec[e]);
	}
	if(n==1) {cout << 0 << endl; return;}
	// cout << "MAX-MIN: " << MAX-MIN <<endl;
	ans.pb(MAX-MIN);
	MAX = LLONG_MIN;
	MIN = LLONG_MAX;
	for(int e = 1 ;e <n ; e++) vec[e] = vec[e]+vec[e-1];

	for(int e = 1; e < divisores.size(); e++){
		ll bloque = divisores[e];
		ll anterior = 0;
		if( bloque <= n/2){
			// cout << "bloque: " << bloque << endl;
			for(int e = bloque ;e <= n ; e+=bloque){
				ll conte = vec[e-1] - anterior;
				MAX = max(MAX,conte);
				MIN = min(MIN, conte);
				anterior = vec[e-1];
			}
			// cout << "MAX-MIN: " << MAX-MIN <<endl;
			ans.pb(MAX-MIN);
			MAX = LLONG_MIN;
			MIN = LLONG_MAX;
		}else{
			break;
		}
	}
	ll rpta = INT_MIN;
	for(auto it = ans.begin(); it != ans.end() ; it++){
		rpta = max(rpta, *it);
	}
	cout << rpta << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifdef DEBUG
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t; cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}