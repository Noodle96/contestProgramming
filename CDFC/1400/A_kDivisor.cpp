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
	ll n,k;
	cin>>n>>k;
	vector<ll> ans;
	for(ll i = 1; i *i <=n ; i++){
		if(n % i == 0){
			if(n/i == i) ans.pb(i);
			else{ans.pb(n/i); ans.pb(i);}
		}
	}

	// for(auto it = ans.begin(); it != ans.end() ; it++){
	// 	cout << *it << " ";
	// }cout << endl;
	sort(ans.begin(), ans.end());
	if(k > ans.size()){cout << -1 << endl;}
	else{
		cout << ans[k-1] << endl;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}