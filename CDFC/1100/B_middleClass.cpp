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

const int N = 1e5+5;
ll ar[N];

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

void solve(){
	int n; double x;
	cin>>n>>x;
	for(int e = 0 ;e < n ; e++){
		cin>> ar[e];
	}
	sort(ar, ar+n, greater<ll>());
	for(int e = 1 ;e < n ; e++){
		ar[e] = ar[e]+ ar[e-1];
	}
	for(int e = n-1 ; e >= 0; e--){
		if(double( ar[e])/double(e+1) >= x){
			cout << e+1 << endl; return;
		}
	}
	cout << 0 << endl;

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