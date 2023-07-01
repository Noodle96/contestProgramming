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
	int n,k,q; cin>>n>>k>>q;
	vector<int> playersPoints(n,k);
	map<int,int> Q; int temp;
	//mapeado
	for(auto e = 0 ; e < q;	 e++){
		cin>>temp;
		Q[temp-1]++;
	}
	//
	for(int e = 0 ;e < n ; e++){
		playersPoints[e] -= (q - (Q[e]));
	}
	// for(auto it = playersPoints.begin(); it != playersPoints.end() ; it++){
	// 	cout << *it  <<" ";
	// }cout << endl;
	int contador = 0;
	for(int e = 0 ; e < n; e++){
		if(playersPoints[e] > 0) msg("Yes","");
		else msg("No","");
	}

}
int main(){
	solve();
	return 0;
}