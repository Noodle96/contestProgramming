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
const int N = 200200;
int candies[N];
void solve(){
	int n,q; cin>>n>>q;
	for(int e = 0 ; e < n ; e++)cin>>candies[e];
	sort(candies, candies+n, greater<int>());
	//prefix sum
	for(int e =  1;e < n ; e++){
		candies[e] = candies[e-1] + candies[e];
	}
	// for(int e = 0 ;e < n ; e++){
	// 	cout << candies[e] << " ";
	// }cout << endl;
	// return;
	int querie;
	while(q--){
		cin>>querie;
		auto lb = lower_bound(candies, candies+n, querie);
		int position = lb-candies;
		if(position >= n){
			cout << -1 << endl;
		}else{
			cout << position+1 << endl;
		}
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
		solve();
	}
	
	return 0;
}