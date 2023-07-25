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
	int n, x; cin>>n>>x;
	if(n<=2){cout << 1 << endl; return;}
	int p = 3;
	int i = 2;
	while(true){
		if(n<= p+x-1){
			cout << i << endl; return;
		}else{
			p = p+x;
		}
		i++;
	}
}
int main(){
	int t; cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}