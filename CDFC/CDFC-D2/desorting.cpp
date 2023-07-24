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
bool isOrdered(vector<ll> &vec){
	for(int e = 0 ;e < vec.size()-1 ; e++){
		if(vec[e] > vec[e+1]) return false;
	}
	return true;
}
void solve(){
	int n; cin>>n;
	vector<ll> vec(n);
	for(int e = 0 ; e < n; e++) cin>>vec[e];

	if(!isOrdered(vec)){cout << 0 << endl; return;}

	vector<ll> vec2(n-1);
	for(int e = 0 ;e < n-1 ; e++) vec2[e] = abs(vec[e]-vec[e+1]);
	sort(all(vec2));
	ll min = vec2[0];
	cout << min/2 +1 << endl;
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