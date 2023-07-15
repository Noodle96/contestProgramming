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
	string s;
	cin>>s;
	vector<bool> vec;
	for(int e = 0; e < s.size(); e++ ){
		if(s[e] == 'a' || s[e] == 'e' || s[e] == 'i' || s[e] == 'o' || s[e] == 'u')vec.pb(true);
		else vec.pb(false);
	}
	bool first = vec[0];
	for(int e = 1 ;e < vec.size() ; e++){
		if(vec[e] != first){
			first = vec[e];
		}else{
			cout << 0 << endl; return;
		}
	}
	cout << 1 << endl;
}
int main(){
	solve();
	return 0;
}