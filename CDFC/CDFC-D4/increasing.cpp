#include <bits/stdc++.h>
using namespace std;
bool f(vector<long long> &vec, int n){
	for(auto e = 0 ;e < n-1 ; e++){
		if(vec[e] == vec[e+1]) return false;
	}
	return true;
	
}
int main(){
	int t; cin>>t;
	int n;
	vector<long long> vec;
	while(t--){
		cin>>n; vec.resize(n);
		for(auto e = 0 ; e < n; e++) cin>>vec[e];
		sort(vec.begin(), vec.end());
		 cout << (f(vec,n)?"YES":"NO") << endl;

		vec.clear();
	}
	return 0;
}