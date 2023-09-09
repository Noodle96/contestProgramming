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
	int n;cin>>n;
	map<int,int> map;
	for(int e = 1 ; e <=9; e++){
		if(n%e == 0) map[e] = n/e;
	}
	// for(auto it = map.begin(); it != map.end() ; it++){
	// 	cout << it->first << " " << it->second << endl;
	// }
	// return;
	bool flag;
	for(int i = 0 ; i <= n; i++){
		flag = false;
		for(auto it = map.begin() ;it != map.end() ; it++){
			if(i % it->second == 0){
				cout << it->first;
				flag = true;
				break;
			}
		}
		if(!flag) cout << "-";
	}
	cout << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}