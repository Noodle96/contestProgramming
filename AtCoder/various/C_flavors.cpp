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

bool comp(const pair<int,int> &a,  const pair<int,int> &b) 
{ 
  return (a.first > b.first); 
}

void solve(){
	int n; cin>>n;
	ll flavor, delicious;
	vector<pii> vec(n);
	for(int e = 0 ; e < n; e++){
		cin>> flavor>> delicious;
		vec[e] = {delicious, flavor};
	}
	sort(all(vec), comp);
	// cout << "print: " << endl; 
	// for(int e = 0 ;e < n ; e++){
	// 	cout << vec[e].first << " " << vec[e].second << endl;
	// }
	int ans = INT_MIN;
	int e = 0 ;
	// int firstMaximo = vec[e].first;
	// int secondMaximo = vec[e].second;
	auto flavorMaximo = vec[e];
	// cout << flavor.second << endl;
	e++;
	for(; e < n; e++){
		if( flavorMaximo.second == vec[e].second){
			ans = max(ans, flavorMaximo.first+ vec[e].first/2);
		}else{
			ans = max(ans, flavorMaximo.first + vec[e].first );
			break;
		}
	}
	cout << ans << endl;
}
int main(){
	solve();
	return 0;
}