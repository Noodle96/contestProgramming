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

const int N = 11000000;
vector<int> dp; //dp.size() = 10000


void printDp(){
	for(int e = 0 ;e < dp.size() ; e++){
		cout << dp[e] << " ";
	}cout << endl;
}

int sum10(int n){
	int ans = 0;
	while(n){
		ans += n%10;
		n/=10;
	}
	return ans;
}

void solve(){
	int k; cin>>k;
	cout << dp[k-1] << endl;
}
int main(){
		
	for(int e = 19 ; e < N ; e++){
		if( sum10(e) == 10) dp.pb(e);
	}
	
	// printDp();
	// cout << "size: " << endl;
	// cout << dp.size() << endl; // 282

	solve();

	return 0;
}