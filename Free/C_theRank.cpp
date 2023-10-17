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
bool cmp(pii &a, pii &b){
	if(b.first == a.first){
		return a.second < b.second;
	}else return a.first > b.first;
}
void solve(){
	int n; cin>>n;
	int temp;
	vector<pii> vec;
	for(int e = 1 ; e <= n; e++){
		int sum = 0;
		for(int j = 0 ; j < 4; j++){
			cin>>temp;
			sum += temp;
		}
		vec.pb({sum,e});
	}
	sort(all(vec), cmp);
	// cout << "print pairs" << endl;
	// for(int e = 0 ;  e < n;e++){
	// 	cout << vec[e].first << " " <<vec[e].second << endl;
	// }
	for(int e = 0 ; e < n; e++){
		if(vec[e].second == 1){cout << e+1 << endl;return;}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}