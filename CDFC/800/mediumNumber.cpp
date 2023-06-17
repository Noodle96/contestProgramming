#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
void solve(){
	vector<int> vec(3);
	for(auto &e: vec)cin>>e;
	sort(all(vec));
	cout << vec[1] << endl;

}
int main(){
	int t; cin>>t;
	while(t--){
		solve();
	}
	return 0;
}