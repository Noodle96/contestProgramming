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
ll a,b;
bool dfs(ll v, vector<ll> &data){
	if(v > b) return false;
	if(v == b){
		data.pb(v);return true;
	}
	if(dfs(2*v, data)){data.pb(v);return true;}
	if(dfs(10*v+1,data)){data.pb(v);return true;}
	return false;
}

void solve(){
	cin>>a>>b;
	vector<ll> data;
	if(dfs(2*a,data)){data.pb(a);} 
	if(dfs(10*a+1,data)){data.pb(a);}
	
	if(data.size() == 0){
		cout << "NO\n"; return;
	}
	msg("YES\n",data.size());
	for(auto it = data.rbegin(); it != data.rend() ; it++){
		cout << *it << " ";
	}cout << endl;
	// while (!data.empty()){
	// 	cout<< data.top() << " ";
	// 	data.pop();
  	// }cout << endl;
}
int main(){
	// #ifndef IN_OUT
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
	solve();
	return 0;
}