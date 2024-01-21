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

ll maxRoot(ld a, ld b, ld c){
	ld dis = b*b - 4*a*c;
	ld r1 = (-b - sqrt(dis) )/2.0;
	ld r2 = (-b + sqrt(dis) )/2.0;
	return floor(max(r1,r2));
}
void solve(){
	ld n; cin>>n;
	cout << maxRoot(1,1,-2*n) << endl;
}
int main(){
	// int a,b,c;
	// cin>>a>>b>>c;
	// cout << maxRoot(a,b,c) << endl;
	int t; cin>>t;
	while(t--){
		solve();
	}
	// cout << max(3.124, 3.1245) << endl;
	
	return 0;
}