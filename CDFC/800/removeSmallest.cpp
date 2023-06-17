#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;

void solve(){
	int n; cin>>n;
	vector<int> vec(n);
	for(auto &e:vec) cin>>e;
	sort(all(vec));
	for(int e = 0 ;e < n-1 ; e++){
		if(  abs(vec[e]-vec[e+1]) >=2 ){
			cout << "NO" << endl; return;
		}
	}
	cout <<"YES" << endl;
}
int main(){
	int t; cin>>t;
	while(t--){
		solve();
	}
	return 0;
}