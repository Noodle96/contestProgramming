#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define msg(str,str2) cout << str << str2<< endl
using namespace std;

const int N = 10001;
int dp[N];

void solve(){
	for(int e = 0 ; e <= N; e++) dp[e] = 0;
	// for(auto &e:dp)cout << dp[e] << " ";
	// cout << endl;
	int n; cin>>n;
	int temp;
	for(int e = 0 ; e < n; e++){
		cin>>temp;
		dp[temp]++;
	}
	int cont = 0 ;
	for(int  e = 0 ;e < N ; e++){
		if(dp[e] != 0){
			cont += dp[e]-1;
		}
	}
	if(cont %2 == 0)msg(n-cont,"");
	else msg(n-cont-1,"");
}
int main(){
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