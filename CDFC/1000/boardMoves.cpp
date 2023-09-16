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
const int N = 250500;
ll l[N];


void solve(){
	int n; cin>>n;
	ll firstSquare = (n-1)/2;
	// cout << firstSquare << endl;
	// cout << l[firstSquare] << endl;
	cout << 4*l[firstSquare] + 2*firstSquare*(firstSquare+1) << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//preprocessing
	for(ll e = 1 ; e < N; e++){
		l[e] = (2*e-1)*e;
	}
	for(ll e = 2 ; e < N; e++){
		l[e] = l[e]+l[e-1];
	}
	// for(int e = 1 ;e < 10 ; e++){
	// 	cout << l[e] << endl;
	// }
	int t; cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}