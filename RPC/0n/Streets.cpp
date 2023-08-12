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
	int n, q; cin>>n>>q;
	map<string, int> mapa;
	string name;
	for(int e = 1 ;e <= n ; e++){
		cin>>name;
		mapa[name] = e;
	}
	string name1, name2;
	for(int e = 0 ; e < q; e++){
		cin>>name1>>name2;
		cout << abs(mapa[name1]-mapa[name2])-1 << endl;
	}
}
int main(){
	// #ifndef IN_OUT
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
	
	solve();
	return 0;
}