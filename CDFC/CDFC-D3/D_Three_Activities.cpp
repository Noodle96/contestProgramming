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
using vll = vector<ll>;

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
int n;
ll solve1(vll &a, vll &b, vll &c ){
	//case ABC
	ll ans = 0;
	ll m = LLONG_MIN;
	ll idx_a = 0;
	for(int e = 0 ;  e < n ; e++){
		if(a[e] > m){
			idx_a = e;
			m = a[e];
		}
	}
	ans += m;
	m = LLONG_MIN;
	ll idx_b =  0;
	for(int e = 0 ;e  < n ;e++){
		if(b[e] > m && e != idx_a){
			idx_b = e;
			m = b[e];
		}
	}
	ans += m;
	m = LLONG_MIN;
	ll idx_c = 0;
	for(int e = 0 ; e < n; e++){
		if(c[e] > m && e != idx_a && e != idx_b){
			idx_c = e;
			m = c[e];
		}
	}
	ans += m;
	return  ans;
}
void solve(){
	cin>>n;
	vector<ll> a(n),b(n),c(n);
	for(int e = 0 ; e < n; e++) cin>> a[e];
	for(int e = 0 ; e < n; e++) cin>> b[e];
	for(int e = 0 ; e < n; e++) cin>> c[e];
	ll ans = LLONG_MIN;
	ans = max( solve1(a,b,c), ans);
	ans = max( solve1(a,c,b), ans);
	ans = max( solve1(b,a,c), ans);
	ans = max( solve1(b,c,a), ans);
	ans = max( solve1(c,a,b), ans);
	ans = max( solve1(c,b,a), ans);
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