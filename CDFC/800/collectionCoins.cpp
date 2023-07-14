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
#define fi first
#define se second
void solve(){
	vector<int> coins(3);
	int n;
	int total = 0;
	for(int e = 0 ; e < 3; e++){
		cin>> coins[e];
		total += coins[e];
	}
	cin>>n;
	total += n;
	auto maximo = max_element(coins.begin(), coins.end());
	if(total%3 == 0 && *maximo <= total/3) cout << "YES" << endl;
	else cout << "NO" << endl;
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