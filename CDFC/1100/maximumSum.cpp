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

bool limites(int low, int up, vector<ll> &vec){
	if(vec[low]+ vec[low+1] <= vec[up]) return true;
	return false;
}
void solve(){
	int n,k; cin>>n>>k;
	vector<ll> vec(n);
	for(ll &e:vec)cin>>e;
	sort(all(vec));
	vector<ll> prefixSum(n+1);
	prefixSum[0] = 0;
	for(int e = 0 ;e < n ; e++){
		prefixSum[e+1] = prefixSum[e] + vec[e];
	}
	ll ans  = 0 ;
	for(int e = 0 ; e <= k; e++){
		ans = max(ans, prefixSum[n-(k-e)] - prefixSum[2*e]);
	}
	cout << ans << endl;

	
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