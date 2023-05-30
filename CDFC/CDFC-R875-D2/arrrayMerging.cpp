#include <bits/stdc++.h>
using namespace std;
// using LL = long long;
#define LL long long


LL f(map<LL,LL> &mappp){
	LL maximo = LONG_MIN;
	for(auto it = mappp.begin() ; it != mappp.end(); it++){
		// if(it->second > maximo) 
		maximo = max(it->second,maximo);
	}
	return maximo;
}
int main(){
	LL t; cin>>t;
	LL n;
	map<LL,LL>mapping;
	LL temp;
	while(t--){
		cin>>n;
		for(LL e = 0 ;e <n ; e++){
			cin>>temp;
			++mapping[temp];
		}
		for(LL e = 0 ;e <n ; e++){
			cin>>temp;
			++mapping[temp];
		}
		cout << f(mapping) << endl;
		mapping.clear();
	}
	return 0;
}