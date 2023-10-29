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

int gcd(int a,int b){
	if(a%b==0) return b;
	else return gcd(b,a%b);
}

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
void solve(){
	ll n; cin>>n; 
	if(n== 1){cout << "NO" << endl; return;}
	ll sum = n*(n+1)/2;
	if(sum & 1){
		cout << "NO" << endl;
	}else{
		sum /=2;
		vector<ll> ans,ans2;
		ll total = n;
		ans.pb(n);
		for(ll e = n-1; e >= 1; e--){
			if(total + e > sum){
				ans2.pb(e);
			}else{
				total += e;
				ans.pb(e);
			}
		}
		cout << "YES" << endl;
		cout << ans.size() << endl;
		for(auto e: ans){
			cout << e << " ";
		}cout << endl;
		cout << ans2.size() << endl;
		for(auto e: ans2){
			cout << e << " ";
		}cout << endl;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}