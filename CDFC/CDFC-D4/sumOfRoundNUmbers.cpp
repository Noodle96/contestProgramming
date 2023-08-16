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
	int n; cin>>n;
	string s = to_string(n);
	int cont = 0;
	while(n){
		cont++;
		n = n/10;
	}
	// cout << cont << endl;
	vector<int> ans;
	for(int e = 0 ; e < s.size(); e++){
		// cout << "s[e]: " << s[e] << endl;
		if(s[e]-'0' != 0){
			ans.pb((s[e]-'0')*pow(10,cont-1));
		}
		cont--;
	}
	cout << ans.size() << endl;
	for(int e = 0 ;e < ans.size() ; e++){
		cout << ans[e] << " ";
	}cout << endl;
	
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