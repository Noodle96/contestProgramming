#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define HERE cout << "i here" << endl;
using namespace std;
void solve(){
	int n,c; cin>>n>>c;
	map<int,int> map;
	int temp;
	for(auto e = 0 ; e < n; e++){
		cin>>temp; map[temp]++;
	}
	// for(auto it = map.begin(); it != map.end() ; it++){
	// 	cout << it->first << " : " << it->second << endl;
	// }
	int cont = 0 ;
	for(auto it = map.begin() ; it != map.end(); it++){
		cont += min(it->second,c) ;
	}
	cout << cont << endl;
}
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t; cin>>t;
	while(t--){
		solve();
	}
	return 0;
}