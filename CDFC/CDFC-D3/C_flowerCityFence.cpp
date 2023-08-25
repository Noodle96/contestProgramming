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

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
void solve(){
	int n; cin>>n;
	vector<int> vec(n);
	for(int e = 0  ; e<n ; e++) cin>>vec[e];
	// cout << "original: " << endl;
	// for(int e = 0; e < vec.size(); e++){
	// 	cout << vec[e] << " ";
	// }cout << endl;
	if(n != vec[0]){
		cout << "NO" << endl; return;
	}
	vector<int> cpy = vec;
	reverse(all(cpy));
	vector<int> ans;
	for(int e = 1 ; e <= n; e++){
		auto lb = lower_bound(all(cpy),e);
		int position = lb - cpy.begin();
		ans.pb(n-position);
	}
	// cout << "ans: " << endl;
	// for(int e = 0; e < ans.size(); e++){
	// 	cout << ans[e] << " ";
	// }cout << endl;
	for(int e = 0 ;e < vec.size() ; e++){
		if(vec[e] != ans[e]){
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
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