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
	int n; cin>>n;
	vector<int> vec(n);
	for(int e = 0 ; e < n; e++)cin>>vec[e];
	int k = vec[0];
	for(int e = 1 ;e < n ; e++){
		if(vec[e] <= k)vec[e]++;
		k = vec[e];
	}
	map<int , int> map;
	for(int e = 0 ;e < n ; e++) map[vec[e]]++;
	cout << map.size() << endl;
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