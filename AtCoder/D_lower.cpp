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
	string s; cin>>s;
	int q ; cin>>q;
	unsigned short int t; int x; char c;
	bool UPPERCASE = false;
	bool LOWERCASE = false;
	map<int, char> map;
	for(int e = 0 ;e < q ; e++){
		cin>>t>>x>>c;
		if(t == 1){
			s[x-1] = c;
			map[x-1] = c;
			// cout <<"s after: " << endl;
			// cout << s << endl; 
		}else if(t==2){
			LOWERCASE = true;
			UPPERCASE = false;
			map.clear();
			//all uppercase
			// for(int e = 0 ;e < n ; e++){
			// 	s[e] = tolower(s[e]);
			// }
			// cout <<"s after: " << endl;
			// cout << s << endl; 
		}else{ // t == 3
			LOWERCASE = false;
			UPPERCASE = true;
			map.clear();
			// for(int e = 0 ;e < n ; e++){
			// 	s[e] = toupper(s[e]);
			// }
			// cout <<"s after: " << endl;
			// cout << s << endl; 
		}
	}
	// cout << "fibnal:"  << endl;
	if(UPPERCASE){
		for(int e = 0 ;e < n ; e++){
			s[e] = toupper(s[e]);
		}
	}
	if(LOWERCASE){
		for(int e = 0 ;e < n ; e++){
			s[e] = tolower(s[e]);
		}
	}
	
	for(auto it = map.begin() ;it != map.end() ; it++){
		s[it->first] = it->second;
	}
	cout << s << endl;
}
int main(){
	solve();
	return 0;
}