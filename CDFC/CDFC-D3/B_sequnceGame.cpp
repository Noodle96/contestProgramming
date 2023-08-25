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
	vector<int> b(n);
	bool onlyOne = true;
	for(int e = 0 ;e < n ; e++){
		cin>>b[e];
		if(b[e] != 1) onlyOne = false;
	}

	vector<int> a;
	a.pb(b[0]);
	for(int  e = 1; e < n; e++){
		if(b[e] == 1 && b[e-1] != 1){
			// if(e-1 != 0) a.pb(1);
			// a.pb(1);
			a.pb(1);
			a.pb(b[e]);
		}else{
			int m = min(b[e], b[e-1]);
			m--;
			if(m != 0) a.pb(m);
			a.pb(b[e]);
		}
	}
	// if(!onlyOne){
	// 	if(b[n-1] == 1) a.pb(1);
	// }
	
	cout << a.size() << endl;
	for(int e = 0 ;e < a.size() ; e++){
		cout << a[e] << " ";
	}cout << endl;
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