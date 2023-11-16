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
int arr[N][M];
int dp[N][M];
void solve(){
	int n,m; cin>>n>>m;
	for(int e = 0; e < n; e++)
		for(int j = 0 ; j < m; j++)
			cin>>arr[e][j];
	for(int e = 0 ; e < m; e++) dp[n-1][e] = arr[n-1][e];

	for(int e = n-2; e >= 0 ; e-- ){
		dp[e][0] = min(arr[e][0]+ dp[e+1][0], arr[e][0]+dp[e+1][1]);
		int j = 1; 
		for(; j<m-1; j++){
			dp[e][j] = min(arr[e][j]+dp[e+1][j-1],
							min(arr[e][j]+dp[e+1][j], arr[e][j]+dp[e+1][j+1]));
		}
		//j ya se aumento
		dp[e][j] = min(arr[e][j]+ dp[e+1][j-1], arr[e][j]+dp[e+1][j]);
	}
	int ans = INT_MAX;
	for(int e = 0 ; e< m; e++){
		ans = min(ans, dp[0][e]);
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
	solve();
	return 0;
}