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
int temp;
int n,m;
int a,b;
const int N = 1e6+10;
vector<int> adj[N];

void solve(){
	while(cin>>n>>m){
		// map<int,vector<int>> map;
		// for(int e = 0 ; e < n; e++){
		// 	cin>>temp;
		// 	map[temp].pb(e+1);
		// }
		// print map
		// for(auto e: map){
		// 	cout << "e->" << e.first  << ": ";
		// 	for(auto j: e.second){
		// 		cout << j << " ";
		// 	}cout << endl;
		// }
	// 	for(int e = 0 ; e < m; e++){
	// 		cin>>a>>b;
	// 		if(a <= map[b].size()){
	// 			cout << map[b][a-1] << endl;
	// 		}else{
	// 			cout << 0 << endl;
	// 		}
	// 	}
	// }
		for(int e = 0 ; e < n; e++){
			cin>>temp;
			adj[temp].pb(e+1);
		}
		for(int e = 0 ; e < m; e++){
			cin>>a>>b;
			if(a <= adj[b].size()){
				cout << adj[b][a-1] << endl;
			}else{
				cout << 0 << endl;
			}
		}
		for(int e = 0 ; e < N; e++){
			adj[e].clear();
		}
	}
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