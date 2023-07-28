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



//int this problem 
//f(1) = 2
//f(n) = f(n-1) + 3n+2
// when n = 25820 , f(n) = 1000098972 => 1e9
const int N = 25821;

vector<ll> dp(N);

void printDp(){
	for(int e = 0 ; e < dp.size(); e++){
		cout << "e:  " << e << " -> " << dp[e] << endl;
	}
}

void solve(){
	int cont =0 ;
	int n; cin>>n;
	while(true){
		if(n<2){break;}
		auto lb = lower_bound(all(dp),	n);
		auto position = lb-dp.begin();
		// msg("position:", position );
		// if(position == 0 && n ==2){
		// 	cont++; break;
		// }
		if(n == dp[position]){
			cont++;
			break;
		}else{
			cont++;
			n -= dp[position-1];
		}
		// cout << "n: " << n << endl;
	}
	cout << cont << endl;
}

int main(){

	dp[0] = 2;
	for(int e = 1  ; e < N; e++){
		dp[e] =  dp[e-1] + 3*e +2;
		// cout << "e:  " << e << " -> " << dp[e] << endl;
		// if(dp[e] >= 1000000000){
		// 	cout << "final: " << e << endl;
		// 	break;
		// }
	}
	int t; cin>>t;
	while(t--){
		solve();
	}
	


	// printDp();

	
	return 0;
}