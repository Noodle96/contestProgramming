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
	int n; cin>>n;
	vector<int> vec(n);
	for(int e  = 0 ; e < n; e++) cin>>vec[e];
	if(vec[0] != vec[1]){
		if(vec[1] != vec[2]) {cout << 2 << endl; return;}
		else {cout << 1 << endl; return;}
	}
	for(int e = 0 ;e < n-1 ; e++){
		if(vec[e] != vec[e+1]){
			cout << e+1+1 << endl;return;
		}
	}
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