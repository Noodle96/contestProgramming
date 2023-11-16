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

const int N = 20;
int colores[N][3]; //FORMA 3
int dp[N][3]; // FORMA 3

void solve(int caso){
	cin.ignore();
	string s; getline(cin,s);
	int n; cin>>n;
	// int colores[n][3]; // FORMA 1
	// vector< vector<int> > colores(n, vector<int>(3)); // FORMA 2
	//with basura
	// for(int e = 0 ;e < n ; e++){
	// 	for(int j = 0 ; j < 3; j++){
	// 		cout << colors[e][j] << " ";
	// 	}cout << endl;
	// }cout << endl;
	for(int e = 0 ;e < n ; e++){
		for(int j = 0 ; j < 3; j++){
			cin>> colores[e][j];
		}
	}
	if(n == 1){cout << min(colores[0][0], min(colores[0][1],colores[0][2])) << endl; return;}
	// int dp[n][3];// FORMA 1
	// vector< vector<int> > dp(n, vector<int>(3)); // FORMA 2
	// for(int e = 0 ;e < n ; e++){
	// 	for(int j = 0 ; j < 3; j++){
	// 		cout << dp[e][j] << " ";
	// 	}cout << endl;
	// }cout << endl;
	// return;
	dp[n-1][0] = colores[n-1][0];
	dp[n-1][1] = colores[n-1][1];
	dp[n-1][2] = colores[n-1][2];
	for(int e = n-2; e>=0; e--){
		dp[e][0] = colores[e][0] + min(dp[e+1][1], dp[e+1][2]);
		dp[e][1] = colores[e][1] + min(dp[e+1][0], dp[e+1][2]);
		dp[e][2] = colores[e][2] + min(dp[e+1][0], dp[e+1][1]);
	}
	cout <<"Case " << caso << ": " << min(dp[0][0], min(dp[0][1], dp[0][2])) << endl;
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