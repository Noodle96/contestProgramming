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
	int a,b,c; cin>>a>>b>>c;
	if(a+b>=10 || a+c >=10 || b+c >=10){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
}
int main(){
	int t; cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}