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
const int N = 100;
const int M = 100;
int grid[N][M];
int dp[N][M];

void solve(){
	int h,w; cin>>h>>w;
	for(int e = 0 ;e <h  ; e++)
		for(int j = 0 ; j < w;j++)
			cin>>grid[e][j];
	//fill the last row of dp
	for(int e = 0 ;e < w ; e++) dp[h-1][e] = grid[h-1][e];
	//fill de abajo hacia arriba
	for(int e = h-2; e>=0; e--){
		dp[e][0] = grid[e][0] +  max(dp[e+1][0],dp[e+1][1]);
		int j = 1;
		for(; j < w-1; j++){
			dp[e][j] = grid[e][j] + max(dp[e+1][j-1], max(dp[e+1][j], dp[e+1][j+1]));
		}
		dp[e][j] = grid[e][j] + max(dp[e+1][j-1], dp[e+1][j]);
	}
	//now, find the max of dp[0][e]
	int ans = INT_MIN;
	for(int e = 0 ;e < w ; e++){
		ans = max(ans,dp[0][e]);
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