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
	string s; cin>>s;
	for(int e = 0 ;e < s.size() ; e++){
		if(e&1){ // impar 1 , 3, 5
			if(s[e] == 'L' || s[e] == 'U' || s[e] == 'D') continue;
			else{cout << "No\n"; return;}
		}else{ // par 0,2,4
			if(s[e] == 'R' || s[e] == 'U' || s[e] == 'D') continue;
			else{cout << "No\n"; return;}
		}
	}
	cout << "Yes\n";
}
int main(){
	solve();
	return 0;
}