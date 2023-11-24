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
const int N = 50;
int ar[N];
int ar2[N+1];
void solve(){
	int n,x;
	cin>>n>>x;
	for(int e = 0 ;e < n ; e++) cin>> ar[e];
	ar2[0] = ar[0];
	for(int e = 1; e < n; e++) ar2[e] = ar[e]-ar[e-1];
	// for(int e= 0 ; e < n; e++){
	// 	cout << ar2[e] << " ";
	// }cout << endl;
	ar2[n] = 2*(x-ar[n-1]);
	int ans = INT_MIN;
	for(int e = 0 ; e <=n ; e++){
		ans = max(ans, ar2[e]);
	}
	cout << ans << endl;

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifdef DEBUG
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t; cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}