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
#define fi first
#define se second
void solve(){
	int n; cin>>n;
	vector<string> vec(n);
	int totalChar = 0;
	for(auto e = 0 ; e < n; e++){
		cin>>vec[e];
		totalChar += vec[e].size();
	}
	//fill map
	map<char,int> map;
	for(int e = 0 ; e< n; e++){
		for(int j = 0; j < vec[e].size() ; j++){
			map[vec[e][j]]++;
		}
	}
	if(totalChar % n == 0){
		int lenOfVector = totalChar/n;
		for(auto it = map.begin() ; it != map.end(); it++){
			if(it->second % n != 0){
				cout << "NO" << endl; return;
			}
		}
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
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