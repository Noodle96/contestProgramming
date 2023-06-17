#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
void solve(){
	vector<int> vec(7);
	for(int &e:vec)cin>>e;
	sort(all(vec));
	// cout << "Print array" << endl;
	// for(auto it = vec.begin(); it != vec.end() ; it++){
	// 	cout << *it << endl;
	// }

	if(vec[0] + vec[1] + vec[2] == vec[6]){
		cout << vec[0] << " " << vec[1] << " " << vec[2] << endl;
	}else{
		cout << vec[0] << " " << vec[1] << " " << vec[3] << endl;
	}
}
int main(){
	int t; cin>>t;
	while(t--){
		solve();
	}
	return 0;
}