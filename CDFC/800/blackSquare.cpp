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
	vector<int> calories(4);
	for(int e = 0  ; e < 4; e++) cin>> calories[e];
	string s; cin>> s;
	int total = 0;
	for(int e = 0 ;e < s.size() ; e++){
		// msg("total: ", total);
		total += calories[s[e] - '0'-1];
	}
	cout << total << endl;
}
int main(){
	solve();
	return 0;
}