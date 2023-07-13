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
	map<int,int> mapa;
	for(int e= 0, a,b; e < n; e++){
		cin>>a>>b;
		mapa[a] = a+b;
	} 
	int a,b;
	for(auto it = mapa.begin() ; it != mapa.end(); it++){
		a = it->first; b = it->second;
		if(mapa.count(b) > 0){
			if(mapa[b] == a){cout << "YES\n"; return; }
		}
	}
	cout << "NO\n";
}
int main(){
	solve();
	return 0;
}