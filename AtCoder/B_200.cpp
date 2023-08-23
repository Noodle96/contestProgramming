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

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
ll f(ll n){
	string s = to_string(n);
	s += "200";
	return stoll(s);
}

void solve(){
	ll n,k; cin>>n>>k;
	for(int e = 0 ; e <k; e++){
		if(n%200 == 0){
			n /=200;
			// cout << "n: " << n << endl;
		}else{
			n = f(n);
			// cout << "n: " << n << endl;
		}
	}
	// cout << "final n: " << n << endl;
	cout << n << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();	
	return 0;
}