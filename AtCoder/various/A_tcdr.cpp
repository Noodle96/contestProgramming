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
	string s; cin>>s;
	for(int e = 0 ;e < (int)s.size() ;e++){
		// if(s[e] != 'a'){
		// 	cout <<s[e] << " dif" << endl;
		// }
		if(s[e] == 'a' || s[e] == 'e' || s[e] == 'i'|| s[e] == 'o' || s[e] == 'u'){
			;
		}else cout << s[e];
	}
	cout << endl;
}
int main(){
	solve();
	return 0;
}