// https://vjudge.net/contest/594111
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
int grid[2*N-1][N];
int dp[2*N-1][N];

void solve(int caso){
	for(int e = 0 ;e < 2*N-1; e++){
		for(int j = 0 ; j < N ;j++){
			dp[e][j] = INT_MIN;
		}
	}
	int n; cin>>n;
	int numCols = 1;
	int e = 0;
	for( ; e < n ; e++){
		for(int j = 0 ; j < numCols; j++){
			cin>> grid[e][j];
		}
		numCols++;
	}
	numCols-=2;
	for(; e <2*n-1 ; e++){
		for(int j = 0; j < numCols; j++ ){
			cin>>grid[e][j];
		}
		numCols--;
	}
	// cout << "grid: " << endl;
	// for(int e = 0 ;e< 2*n -1 ; e++){
	// 	for(int j = 0 ; j < n; j++){
	// 		cout << grid[e][j] << " ";
	// 	}cout << endl;
	// }cout << endl;

	numCols = 1;
	dp[2*n-2][0] = grid[2*n-2][0];
	// cout << dp[2*n-2][0] << endl;
	e = 2*n-3;
	for(int r = 0 ; r < n-1 ; r++){
		for(int j = 0 ; j < numCols ; j++){
			int value = dp[e+1][j];
			dp[e][j] = max(grid[e][j] + value, dp[e][j] );
			dp[e][j+1] = max(grid[e][j+1] + value, dp[e][j+1]);
		}
		numCols++;
		e--;
	}

	for(int r= 0 ; r < n; r++){
		for(int j = 0 ; j < numCols; j++){
			int value = dp[e+1][j];
			if(j+2 <= numCols) dp[e][j] = max(grid[e][j] + value, dp[e][j] );
			if(j-1 >= 0) dp[e][j-1] = max(grid[e][j-1] + value, dp[e][j-1]);
		}
		e--;
		numCols--;
	}



	// cout << "\ndp: \n";
	// for(int e = 0 ;e< 2*n -1 ; e++){
	// 	for(int j = 0 ; j < n; j++){
	// 		cout << dp[e][j] << " ";
	// 	}cout << endl;
	// }cout << endl;

	cout <<"Case "  << caso << ": "<< dp[0][0] << endl;

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for(int e = 0 ;e < 2*N-1; e++){
		for(int j = 0 ; j < N ;j++){
			grid[e][j] = INT_MIN;
		}
	}
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