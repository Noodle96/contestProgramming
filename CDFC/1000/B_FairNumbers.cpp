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
bool check(ll n){
	string str = to_string(n);
	for(int e = 0 ; e < str.size(); e++){
		if(str[e]-'0' != 0 && n%(str[e]-'0') != 0) return false;
	}
	return true;
}

void solve(){
	ll n; cin>>n;
	for(ll e = n; e < n+10000; e++){
		if(check(e)){
			cout << e << endl;
			return;
		}
	}
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
		// startTime = clock();
		solve();
		// cout << getCurrentTime() << endl;
	}
	
	return 0;
}