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
vector<int> vec;

bool isSorted(vector<int> &vec){
	for(int e = 0 ;e < vec.size() -1; e++){
		if(vec[e] > vec[e+1]) return false;
	}
	return true;
}
bool isSorted2(int l, int r){
	// cout << "l: " << l << " r: " << r << endl;
	for(int e = l ;e < r ; e++){
		if(vec[e] > vec[e+1]) return false;
	}
	return true;
}

void solve(){
	int n; cin>>n; vec.resize(n);
	int max = INT_MIN;
	for(int e = 0,temp ;e < n ; e++){
		cin>>temp;
		vec[e] = temp;
		if(temp > max) max= temp;
	}
	if(isSorted(vec)){cout << 0 << endl; return;}

	int contSort = 0;
	for(auto e = 0 ; e < n ; e++){
		if(  isSorted2(n-1-e,n-1) ){
			contSort++;
		}else break;
		// indexPosition(n-1-e,n-1);
	}

	// if(max == vec[n-1]){
	// 	cout << *max_element(vec.begin(),vec.begin()+(n-1)) << endl;
	// }else{
	// 	cout << max << endl;
	// }
	// cout << "contSort: " << contSort << endl;
	int restantes = n-contSort;
	// cout << "restantes: " << restantes << endl;

	cout << *max_element(vec.begin(), vec.begin() + restantes) << endl;

}
int main(){
	// #ifndef IN_OUT
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
	
	int t; cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}