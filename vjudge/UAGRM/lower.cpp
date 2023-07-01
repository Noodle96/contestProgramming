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
	vector<int> vec(n);
	for(auto &e: vec) cin>>e;
	int maximo = INT_MIN;
	int cont = 0;
	if(n == 1){
		cout << 0 << endl; return;
	}
	for(int e = 0; e < n-1; e++){
		if(vec[e] >= vec[e+1]){
			cont++;
			maximo = max(maximo,cont);
		}else cont = 0;
	}
	cout << max(cont,maximo) << endl;
// 4 4 5 6 6 5 5
}
int main(){
	solve();
	return 0;
}