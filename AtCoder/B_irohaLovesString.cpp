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
	int n, l; cin>>n>>l;
	vector<string> vec(n);
	for(int e = 0 ; e < n; e++){
		cin>>vec[e];
	}
	sort(all(vec));
	string result = "";
	for(int e = 0 ;e < n ; e++){
		result += vec[e];
	}
	cout << result << endl;
}
int main(){
	solve();
	return 0;
}