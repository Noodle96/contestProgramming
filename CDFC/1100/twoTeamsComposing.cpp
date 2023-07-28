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
	map<int, int> mapa;
	int maximo = INT_MIN;
	for(int e = 0,temp ;e < n ; e++){
		cin>>temp;
		mapa[temp]++;
	}
	for(auto it = mapa.begin() ; it != mapa.end(); it++){
		if(it->second > maximo) maximo = it->second;
	}

	int s = int(mapa.size());
	if(s == maximo){cout << maximo-1 << endl; return;}
	if(maximo<s){cout << maximo << endl; return;}
	cout << s << endl;
}
int main(){
	int t; cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}