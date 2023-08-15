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
	string s;
	cin>>s;
	if(s[2] == s[3] && s[4] == s[5]) cout << "Yes" << endl;
	else cout << "No" << endl;
}
int main(){
	solve();
	return 0;
}