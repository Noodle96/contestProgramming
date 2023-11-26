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
const int N = 1e3;
double ar[N];
void solve(){
	int n; cin>>n;
	double l; cin>>l;
	for(int e = 0 ; e < n; e++)cin>>ar[e];
	sort(ar, ar+n);
	double ans = -1.0;
	if(ar[0] != 0.0) ans = max(ans, (ar[0]-0));
	// cout << "ans: " << ans << endl;
	int e = 0;
	for(;e < n-1 ; e++){
		ans = max(ans, (ar[e+1]-ar[e])/2.0);
		// cout << "ans: " << ans << endl;
	}
	if(ar[e] != l) ans = max(ans, (l-ar[e]));
	printf("%.9lf", ans);
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifdef DEBUG
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	solve();
	return 0;
}