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
	int n; cin>>n;
	vector<int> vec(n);
	for(int e = 0 ; e<n; e++)cin>>vec[e];
	if(n == 2){
		cout << abs(vec[1]-vec[0]) << endl;
		return;
	}
	if(n == 3){
		cout << min(abs(vec[2]-vec[0]), abs(vec[1]-vec[0]) + abs(vec[2]-vec[1]) ) << endl;
		return;
	}

	vector<int> dp(n-1);
	dp[n-2] = abs(vec[n-1]-vec[n-2]);
	dp[n-3] = abs(vec[n-1]- vec[n-3]);
	for(int e =  n-4;e >= 0 ; e--){
		dp[e] = min(dp[e+1]+abs(vec[e+1]-vec[e]),dp[e+2]+abs(vec[e+2]-vec[e]) );
	}
	cout << dp[0] << endl;


}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	// #ifndef IN_OUT
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
	
	solve();
	return 0;
}