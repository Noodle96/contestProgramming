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
	string s,s_copy; cin>>s;
	s_copy = s;
	if(s_copy == "abc"){
		cout << "YES" << endl; return;
	}else{
		swap(s_copy[0],s_copy[1]);
		if(s_copy == "abc"){cout << "YES" << endl; return;}
		s_copy = s;
		swap(s_copy[0],s_copy[2]);
		if(s_copy == "abc"){cout << "YES" << endl; return;}
		s_copy = s;
		swap(s_copy[1],s_copy[2]);
		if(s_copy == "abc"){cout << "YES" << endl; return;}
		cout << "NO" << endl;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}