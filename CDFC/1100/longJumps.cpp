#include <bits/stdc++.h>
using namespace std;
using LL = long long;

//O(n^2)
// void solve(){
// 	int n; cin>>n;
// 	vector<LL> vec(n);
// 	for(LL &e: vec) cin>>e;
// 	// for(auto it = vec.begin(); it != vec.end() ; it++){
// 	// 	cout << *it << " "; 
// 	// }cout << endl;
// 	LL score, position;
// 	LL maximo = LONG_LONG_MIN;
// 	for(int e = 0 ; e < n;e++){
// 		score = 0;
// 		position = e+1;
// 		while(position <= n){
// 			score  += vec[position-1];
// 			position += vec[position-1];
// 		}
// 		maximo = max(maximo, score);
// 	}
// 	cout << maximo << endl;
// }

//O(n)
void solve(){
	int n; cin>>n;
	vector<LL> vec(n);
	for(LL &e: vec) cin>>e;
	vector<LL> dp(n);
	for(int i = n-1 ; i >=0; i--){
		dp[i] = vec[i];
		int j = i + vec[i];	
		if(j < n) dp[i] += dp[j];
	}
	// cout << "print" << endl;
	// for(auto it = dp.begin(); it != dp.end() ; it++){
	// 	cout << *it << endl;
	// }
	cout << *max_element(dp.begin(), dp.end()) << endl;
}


int main(){
	int t; cin>>t;
	while(t--){
		solve();
	}

	return 0;
}