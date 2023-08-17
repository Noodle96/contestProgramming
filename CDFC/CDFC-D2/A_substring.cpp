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
string f(string s){
	int n = (int)s.size();
	string temp = "";
	for(int e = 0 ;e < n ; e++){
		temp += "(";
	}
	for(int e = 0 ;e < n ; e++){
		temp += ")";
	}
	return temp;
}
void solve(){
	string s; cin>>s; bool contiguos = false;
	int n = (int)s.size();
	for(int e = 0 ;e< n-1 ; e++){
		if(s[e] == s[e+1]){
			contiguos = true;
			break;
		}
	}
	//particular case
	if(s == "()") {cout << "NO" << endl; return;}
	if(contiguos){
		cout << "YES" << endl;
		for(int e = 0 ; e < 2*n; e++){
			if(e&1) cout << ")";
			else cout << "(";
		}
		cout << endl;
	}else{
		cout << "YES" << endl;
		string tmp = f(s);
		cout << tmp << endl;
		// cout << "no conti" << endl;
	}
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