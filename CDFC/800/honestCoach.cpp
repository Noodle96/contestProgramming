#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define HERE cout << "i here" << endl;
using namespace std;
void solve(){
	int n; cin>>n;
	vector<int> vec(n);
	for(auto &e:vec) cin>>e;
	sort(all(vec));
	vector<int> vec_temp(n);
	vec_temp[0] = INT_MAX;
	for(int e = 1 ; e < n; e++){
		vec_temp[e] = vec[e] - vec[e-1];
	}
	sort(all(vec_temp));
	cout << vec_temp[0] << endl;
	// vec_temp.clear();
	// vec.clear();
}
int main(){
	#ifndef IN_OUT
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
	int t; cin>>t;
	while(t--){
		solve();
	}
	return 0;
}