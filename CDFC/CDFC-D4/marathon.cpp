#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define msg(str,str2) cout << str << str2<< endl
using namespace std;
void solve(){
	vector<int> vec(4);
	for(auto &e:vec)cin>>e;
	int cont = 0;
	for(int e = 1 ; e < 4; e++){
		if(vec[0] < vec[e]) cont++;
	}
	cout << cont << endl;
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