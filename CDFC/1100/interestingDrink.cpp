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
	map<int,int> map;
	for(int e = 0 ; e < n; e++){
		cin>>vec[e];
		map[vec[e]]++;
	}
	//O(nlogn)
	sort(all(vec)); 

	int q;cin>>q;
	vector<int> coins(q);
	
	for(int e = 0 ;e< q ; e++) cin>>coins[e];

	//O(qlogq)
	for(int  e = 0 ; e < q; e++){ //O(q)
		auto lb = lower_bound(all(vec), coins[e]); //O(logq)
		int l = lb-vec.begin();
		if(l == n){
			cout << l << endl; continue;
		}
		if(vec[l] == coins[e]){
			cout << l+1  + map[coins[e]] - 1<< endl;
		}else cout << l << endl;

	}
}

int main(){
	solve();
	return 0;
}