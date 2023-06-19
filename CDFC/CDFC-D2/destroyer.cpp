#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define HERE cout << "i here" << endl;
using namespace std;

void solve(){
	int n; cin>>n;
	map<int,int> map;
	int temp;
	for(int e = 0 ;e < n ; e++){
		cin>>temp;
		map[temp]++;
	}
	//verify MAP
	int e = 0;
	auto it = map.begin();
	for(; it != map.end(); it++, e++){
		if(e != it->first){
			cout << "NO" << endl;return;
		}
	}
	auto before = map.begin();
	auto current = ++map.begin();
	for( ; current != map.end(); current++){
		if(current->second > before->second){
			cout << "NO" << endl;return;
		}
		before = current;
	}
	cout << "YES" << endl;return;
	// for(auto it = map.begin(); it != map.end() ; it++){
	// 	cout << it->first << " : " << it->second << endl;
	// }

}
int main(){
	int t; cin>>t; 
	while(t--){
		solve();
	}
	return 0;
}