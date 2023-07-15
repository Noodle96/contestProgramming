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
	ll a,b,c;
	cin>>a>>b>>c;
	if(a== b+c || b==a+c || c == a+b){cout << 1 << endl;return;}
	if(a== b*c || b==a*c || c == a*b) {cout << 2 << endl;return;}
	cout << 3 << endl;
	
}
int main(){
	solve();
	return 0;
}