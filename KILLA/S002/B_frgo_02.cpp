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
	int n,k; cin>>n>>k;
	vector<int> vec(n);
	for(int e = 0 ;e <n ; e++)cin>>vec[e];
	vector<int> dp(n-1);
	int e = n-2;
	if(n>=k){
		int k_ = k;
		while(k--){
			dp[e] = abs(vec[n-1]-vec[e]); 
			e--;
		}
		for(;e >=0 ; e--){
			int minimo = INT_MAX;
			int temp = e;
			for(int j = 1 ;j <= k_ ; j++){
				minimo = min(minimo, dp[temp+j]+abs(vec[temp+j]-vec[temp]));
				// cout << "\t\t" << minimo << endl;
			}
			dp[e] = minimo;
		}
		// cout << "print dp :" << endl;
		// for(int e = 0 ; e < n-1; e++){
		// 	cout << dp[e] << " ";
		// }cout << endl;
		cout << dp[0] << endl;

	}else{
		while(k--){
			dp[e] = abs(vec[n-1]-vec[e]);
			e--;
			if(e < 0) break;
		}
		cout << dp[0] << endl;
	}
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