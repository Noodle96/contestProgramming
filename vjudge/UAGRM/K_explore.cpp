#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define msg(str,str2) cout << str << str2<< endl
using namespace std;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

#define pb push_back
#define mp make_pair
void solve(){
	int n,m; cin>>n>>m;
	ll t; cin>>t;
	vector<ll> spendRoom(n-1);
	for(int e = 0 ; e < n-1; e++){
		cin>>spendRoom[e];
	}
	ll temp, temp1;
	map<ll,ll> map;
	for(int e = 0 ;e < m ; e++){
		cin>>temp >> temp1;
		map[temp] = temp1;
	}

	// for(int e = 0 ; e < n-1; e++){

	// }
	int e = 0;
	while(e < n-1){
		t -= spendRoom[e];
		if(map.count(e+1) > 0) t += map[e+1];
		if(t<=0) break;
		e++;
	}
	// cout << "e: " << e <<endl;
	if(e == n-1){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
}
int main(){
	solve();
	return 0;
}