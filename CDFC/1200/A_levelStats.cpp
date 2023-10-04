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
const int N = 100;
int p[N];
int c[N];

bool isOrdered(int l[], int n){
	for(int e = 1 ; e < n; e++){
		if(l[e] < l[e-1]) return false;
	}
	return true;
}


void solve(){
	int n; cin>>n;
	for(int e =0 ;e < n ;e++){
		cin>> p[e];
		cin>> c[e];
	}
	if(n==1){
		if(p[0] >= c[0]){cout<< "YES" << endl;}
		else cout << "NO" <<endl;
		return;
	}
	if(!isOrdered(p,n)){cout << "NO" <<endl;return;}
	if(!isOrdered(c,n)){cout << "NO" <<endl;return;}
	if(p[0] >= c[0]){
		for(int e = 1;e < n ; e++){
			if(c[e]-c[e-1] > p[e]-p[e-1]){
				cout << "NO" <<endl;return;
			}
		}
		cout << "YES" << endl;
	}else{
		cout << "NO" <<endl;
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