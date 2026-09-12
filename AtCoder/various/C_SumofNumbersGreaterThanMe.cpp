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
	ll temp;
	map<ll,ll> map;
	vector<ll> ar(n);
	for(int e = 0 ; e < n; e++){
		cin>>temp;
		ar[e] = temp;
		map[temp]++;
	}
	// cout << "print map" << endl;
	// for(auto it = map.begin(); it != map.end() ; it++){
	// 	cout << it->first << " : " << it->second << endl;
	// }cout << endl;

	vector<pair<ll,ll>> vec;
	//copy map to vector of pair
	for(auto it = map.begin() ;it != map.end() ; it++) vec.pb({it->first,it->second});
	// cout << "print vec " << endl;
	// for(int e = 0 ;e < vec.size() ; e++){
	// 	cout << vec[e].first << " " << vec[e].second << endl;
	// }cout << endl;

	//minimo len =2
	//handle the vector of pairs
	int lenVec = vec.size();
	map[vec[lenVec-1].first] = 0;
	for(int e = vec.size()-2; e>=0; e--){
		map[vec[e].first] = map[vec[e+1].first] + vec[e+1].first*vec[e+1].second;
	}
	// cout << "print map" << endl;
	// for(auto it = map.begin(); it != map.end() ; it++){
	// 	cout << it->first << " : " << it->second << endl;
	// }cout << endl;

	for(int e =0 ;e < n ; e++){
		cout << map[ar[e]] << " ";
	}cout << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifdef DEBUG
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	solve();
	return 0;
}