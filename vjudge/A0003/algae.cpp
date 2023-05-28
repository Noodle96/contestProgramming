#include <bits/stdc++.h>
using namespace std;
int main(){
	int r,D,X_i;
	cin>>r>>D>>X_i;
	vector<int> vec(11);
	vec[0] = X_i;
	for(int e = 1 ; e < 11;e++){
		vec[e] = r*vec[e-1] -D;
	}
	for(int e  = 1; e < 11; e++){
		cout << vec[e] << endl;
	}
	return 0;
}