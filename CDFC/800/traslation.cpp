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
	string s1,s2; cin>>s1>>s2;
	int n = s1.size();
	for(int e = 0 ; e < n ; e++){
		if(s1[e] != s2[n-e-1]){
			cout << "NO\n"; return;
		}
	}
	cout << "YES\n";
}
int main(){
	solve();
	return 0;
}