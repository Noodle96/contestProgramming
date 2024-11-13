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

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
void solve(){
	int k; cin>>k;
	string s; cin>>s;
	map<char, int> map;
	for(int e = 0 ;e < (int)s.size() ; e++){
		map[s[e]]++;
	}
	for(auto it = map.begin(); it != map.end() ; it++){
		if(it->second%k != 0){
			cout << -1 << endl; return;
		}else{
			it->second = it->second / k;
		}
	}
	// for(auto it = map.begin(); it != map.end() ; it++){
	// 	cout << it->first << " " << it->second << endl;
	// }
	for(int e = 0 ; e <k; e++){
		for(auto it = map.begin(); it != map.end() ; it++){
			for(int l = 0 ;l < it->second ; l++){
				cout << it->first;
			}
		}
	}
	cout << endl;

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}