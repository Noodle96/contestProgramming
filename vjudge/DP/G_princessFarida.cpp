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

const int N = 1e4;
ll ar[N];
ll dp[N];
void solve(int caso){
	int n; cin>>n;
	for(int e = 0 ;e < n ; e++) cin>>ar[e];
	if(n == 0){cout << "Case " << caso << ": "<< 0 << endl; return;}
	if(n == 1){cout << "Case " << caso << ": "<< ar[0]<< endl; return;}
	if(n == 2){cout << "Case " << caso << ": "<< max(ar[0], ar[1]) << endl; return;}
	dp[n-1] = ar[n-1];
	dp[n-2] = ar[n-2];
	dp[n-3] = ar[n-3] + ar[n-1];
	for(int e = n-4 ;e >= 0 ; e--){
		ll value = ar[e];
		dp[e] = max(value+dp[e+2], value+dp[e+3]);
	}
	cout << "Case " << caso << ": "<<  max(dp[0], dp[1]) << endl;

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifdef DEBUG
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t; cin>>t;
	int caso = 1;
	while(t--){
		solve(caso++);
	}
	
	return 0;
}