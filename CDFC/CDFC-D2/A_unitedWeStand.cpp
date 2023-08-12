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
	map<int,int> map;
	int maximo = INT_MIN;
	for(int e = 0,temp ;e < n ; e++){
		cin>>temp;
		if(temp > maximo) maximo = temp;
		map[temp]++;
	}
	// cout << "printMAp: " << endl;
	// for(auto it = map.begin(); it != map.end() ; it++){
	// 	cout << it->first << " : " << it->second << endl;
	// }
	if(map.size() == 1){
		cout << -1 << endl; return;
	}
	cout << n-map[maximo] << " " <<map[maximo] << endl;
	for(auto it = map.begin() ; it != map.end(); it++){
		if(it->first != maximo){
			for(int e = 0 ;e < it->second ; e++){
				cout << it->first << " "; 
			}
		}
	}cout << endl;

	for(int e = 0 ; e < map[maximo]; e++){
		cout << maximo << " ";
	}cout << endl;
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