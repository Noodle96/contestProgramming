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
	int sum = 0;
	for(int e = 0, temp  ;e < n ; e++){
		cin>>temp;
		sum += temp;
	}
	if(sum & 1) cout << "NO" << endl;
	else cout << "YES" << endl;
}
int main(){
	int t; cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}