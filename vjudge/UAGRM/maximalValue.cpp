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
	int n; cin>>n;
	vector<int> vec(n-1);
	for(auto &e:vec) cin>>e;
	int sumaTotal = vec[n-2];
	for(int e = n-2;e > 0 ;e--){
		sumaTotal += min(vec[e], vec[e-1]);
	}
	sumaTotal += vec[0];
	cout << sumaTotal << endl;
}
int main(){
	solve();
	return 0;
}