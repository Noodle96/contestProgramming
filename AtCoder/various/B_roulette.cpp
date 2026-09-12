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

const int N = 100;
vector<int> lista[N];

bool containK(int k, vector<int>&vec){
	for(int e = 0 ;e < vec.size() ; e++){
		if(vec[e] == k) return true;
	}
	return false;
}

void solve(){
	int n; cin>>n;
	for(int e = 0, c ; e < n; e++){
		cin>>c;
		for(int j = 0, value ; j < c; j++){
			cin>>value;
			lista[e].pb(value);
		}
	}
	vector<pii> ans;
	int K; cin>>K;
	for(int e = 0 ; e < n; e++){
		if ( containK(K,lista[e]) ){
			ans.pb(mp(lista[e].size(), e+1));
		}
	}
	sort(all(ans));
	if(ans.size() >= 1){
		int cont = 1;
		for(int e = 0  ;e < ans.size() - 1 ; e++){
			if(ans[e].first == ans[e+1].first) {
				cont++;
			}else{
				break;
			}
		}
		cout << cont << endl;
		for(int e = 0 ; e < cont; e++){
			cout << ans[e].second << " ";
		}cout << endl;
	}else{
		cout << 0 << endl;
	}
// 	for(int e = 0 ; e < ans.size(); e++ ){
// 		cout << ans[e].first << " " << ans[e].second << endl;
// 	}
}
int main(){
	solve();
	return 0;
}