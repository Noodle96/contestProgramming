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
const int N = 2e5;
int ps[N];
void solve(){
	int n,k; cin>>n>>k;
	string s;cin>>s;

	ps[0] = (s[0]=='W'?1:0);
	for(int e = 1 ; e < n; e++){
		ps[e] = ps[e-1]+(s[e]=='W'?1:0);
	}

	int ans = INT_MAX;
	int e = k-1;
	ans = min(ans,ps[e] );
	e++;
	for(; e < n  ; e++){
		ans = min(ans,ps[e] - ps[e-k]);
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