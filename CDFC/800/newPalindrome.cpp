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
	string s; cin>>s;
	map<char,int> mapa;
	for(int e = 0 ;e < s.size() ; e++ ){
		mapa[s[e]]++;
	}
	if(mapa.size() == 1){
		cout << "NO" <<endl; return;
	}
	if(mapa.size() == 2){
		auto current = mapa.begin();
		auto next = ++mapa.begin();

		if(current->second == 1 || next->second == 1){
			cout << "NO" << endl; return;
		}
	}
	// int cont = 0;
	// for(auto it = mapa.begin(); it != mapa.end() ; it++){
	// 	if( it->second %2 != 0 ){
	// 		cont++;
	// 	}
	// }
	// if(cont < 2){
	// 	cout << "YES" << endl;
	// 	return;
	// }
	// cout << "NO" << endl;
	cout << "YES" << endl;
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