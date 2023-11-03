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
	int n; cin>>n;
	vector<int> vec(2*n);
	for(int e = 0 ;e < 2*n ; e++){
		cin>>vec[e];
	}
	sort(all(vec));
	vector<pii> ans;
	for(int e = 0 ; e < n; e++){
		ans.pb({vec[e], vec[e+n]});
	}
	int totalx =  0, totaly = 0;
	for(int e = 1 ;e < n ; e++){
		totalx += (ans[e].first - ans[e-1].first);
		totaly += (ans[e].second - ans[e-1].second);
	}
	cout << totalx + totaly << endl;
	for(auto e: ans){
		cout << e.first << " " << e.second << endl;
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