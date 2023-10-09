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
	vector<int> ans;
	for(int e = 1 ;e*e <= n ; e++){
		if(n%e == 0){
			if(e == n/e){
				ans.pb(e);
			}else{
				ans.pb(e);ans.pb(n/e);
			}
		}
	}
	if(ans.size() >= 5){
		for(int e = 1 ; e< (int)ans.size()-1 ; e++){
			for(int p = e+1; p<=(int)ans.size()-1  ;p++){
				for(int k = p+1; k<=(int)ans.size()-1; k++){
					if(ans[e]*ans[p]*ans[k] == n){
						cout << "YES" << endl;
						cout << ans[e] << " " <<   ans[p] << " " << ans[k] << endl;
						return;
					}
				}
			}
		}
		cout << "NO\n";
	}else{
		cout << "NO\n";
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	// #ifndef IN_OUT
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
	
	int t; cin>>t;
	while(t--){
		// startTime= clock();
		solve();
		// cout << "time for test : " << t+1 << " " << getCurrentTime()  << " seconds"<< endl; 
	}
	return 0;
}