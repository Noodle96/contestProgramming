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

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
void solve(){
	string s; cin>>s;
	string ans;
	for(int e = 0 ;e < s.size() ; e++){
		// cout << ( s[e]-'0') << endl;
		// cout << 9 -( s[e]-'0') <<endl << endl;
		if(s[e]-'0' == 9){
			if(!ans.empty()){
				ans+="0";
			}else{
				ans+="9";
			}
		}else{
			ans += to_string(min(s[e]-'0', 9-(s[e]-'0')));
		}
	}
	cout << ans << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}