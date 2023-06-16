#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()

int main(){
	vector<int> vec(3);
	for(auto &e:vec) cin>>e;
	sort(all(vec));
	cout << (vec[1]-vec[0] + vec[2]-vec[1]) << endl;
	return 0;
}