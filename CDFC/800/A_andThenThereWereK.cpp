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
void solve(){
	int n; cin>>n;
	bitset<30> rb_n;
	for(int e = 30; e>=0; e--){
		if( (n & (1LL<<e)) != 0 ) rb_n.set(e,1);
	}
	// cout << rb_n << endl;
	int position;
	for(int e = 30 ; e >= 0; e--){
		if(rb_n[e] == 1){position = e; break;}
	}
	bitset<30> ans;
	ans[position] = 1;
	cout << ans.to_ulong() -1 << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin>>t;
	while(t--)solve();
	return 0;
}