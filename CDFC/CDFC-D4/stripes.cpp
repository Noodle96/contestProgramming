#include <bits/stdc++.h>
using namespace std;
bool f(vector<char> &vec){
	for(int e = 0 ; e < 7; e++){
		if(vec[e] == '.' or vec[e] == 'B') return false;
		if(vec[e] !=  vec[e+1]) return false;
	}
	return true;
}
int main(){
	int t; cin>>t;
	vector<char> vec(8);
	bool flag = false;
	while(t--){
		for(int e = 0;e < 8 ; e++){
			for(int j = 0 ; j < 8; j++){
				cin>> vec[j];
			}
			if(f(vec)){
				flag = true;
			}
			vec.clear();
		}
		if(flag) cout << "R" <<endl;
		else cout << 'B' <<endl;
		flag = false;
	}
	return 0;
}