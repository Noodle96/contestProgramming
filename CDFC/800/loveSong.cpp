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

// abacaba

string s;
//native solution O(q)O(n)
ll f(int left, int right){
	// cout << "left: " << left << " right " << right << endl;
	map<char,int> map;
	for(int e = left; e <= right; e++){
		map[s[e]]++;
	}
	ll total = 0;
	for(auto it = map.begin() ; it != map.end(); it++){
		total += (it->first - '`')* it->second ;
		// cout << it->first - '`' << " " << it->second << endl;
	}
	return total;
}

void solve(){
	int n,q; cin>>n>>q;
	cin>>s;
	int l,r;
	ll cant;
	vector<int> prefixSum(n);
	prefixSum[0] = s[0] - '`';
	for(int e = 1 ;e < n ; e++){
		prefixSum[e] = (s[e] - '`') + prefixSum[e-1];
	}
	// for(int e = 0 ; e < n; e++){
	// 	cout << prefixSum[e] << " ";
	// }cout << endl;
	// return;
	while(q--){ // O(q)
		cin>>l>>r;
		l--; r--;
		// cant = f(l,r); native solution //O(n)
		if(l == 0) cant = prefixSum[r];
		else cant = prefixSum[r] - prefixSum[l-1]; // O(1)
		cout << cant << endl;
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