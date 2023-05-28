#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,k; cin>>n>>k;
	vector<char> vec(n);
	for(auto e = 0 ;e < n ; e++) cin>>vec[e];
	int cont = 0;
	if(vec[0] == 'R') cont++;
	for(int e = 0 ; e < n-1; e++){
		if(vec[e] == vec[e+1]) cont++;
	}
	if(k-cont > 0) cout << k - cont << endl;
	else cout << 0 << endl;
	return 0;
}