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
void solve(){
	int x,y,n; cin>>x>>y>>n;
	if(n/3 == 0){
		cout << n*x << endl; return;
	}
	//caso 1
	int a = n/3;
	int b = n%3;

	int ans1 = a*y + b*x;
	//caso 2
	int ans2 = x*n;

	cout << min(ans1,ans2) << endl;
}
int main(){
	solve();
	return 0;
}