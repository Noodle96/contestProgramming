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
	pair<int,int> pair;
	map<int,int> mapx,mapy;
	for(int e = 0 ,a,b; e < 3;e++){
		cin>>a>>b;
		mapx[a]++;
		mapy[b]++;
	}
	for(auto it = mapx.begin(); it != mapx.end() ; it++){
		if(it->second == 1) pair.first = it->first;
	}
	for(auto it = mapy.begin(); it != mapy.end() ; it++){
		if(it->second == 1) pair.second = it->first;
	}
	cout << pair.first << " " << pair.second << endl;
}
int main(){
	solve();
	return 0;
}