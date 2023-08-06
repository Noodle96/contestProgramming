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
bool ff(map<ll,ll> &mapa){
	for(auto it = mapa.begin() ;it != mapa.end() ; it++){
		if(it->second != 1) return true;
	}
	return false;
}

void solve(){
	int n; cin>>n;
	vector<ll> numbers(n);
	map<ll,ll> mapa;
	ll sumTotal = 0;
	for(int e = 0,temp ; e < n; e++){
		cin>>temp;
		numbers[e] = temp;
		mapa[temp]++;
		sumTotal += temp;
	}
	if(n==1){cout << "NO" << endl; return;}
	if( !ff(mapa) ){ cout << "YES" <<endl; return;}
	ll sum2 = 0;
	for(int e = 0 ; e < n; e++){
		if(numbers[e] == 1){sum2 += 2;}
		else{sum2 += 1;}
	}
	if(sum2 > sumTotal){
		cout << "NO" << endl;
	}else{
		cout << "YES" << endl;
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