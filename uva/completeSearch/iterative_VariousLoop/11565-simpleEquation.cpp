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

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

void solve(){
	int A,B,C; cin>>A>>B>>C;
	vector< pair<int, pair<int,int>> > ans;
	for(int e = -99 ;e  < 100 ; e++){
		for(int j = -99 ;j < 100 ; j++){
			for(int k = -99 ; k < 100; k++){
				if(e != j and e != k and j != k){
					if(e +j + k == A){
						if(e*j*k == B){
							if(e*e + j*j + k*k == C) ans.pb({e,{j,k}});
						}	
					}
				}
			}
		}
	}
	if(ans.size() > 0){
		sort(all(ans));
		// for(int e = 0 ;e < ans.size() ; e++){
		// 	cout << ans[e].first << " ";
		// 	auto ss = ans[e].second;
		// 	cout << ss.first << " " << ss.second << endl;
		// }
		cout << ans[0].first <<" "<< ans[0].second.first <<" "<< ans[0].second.second << endl; 
	}else{
		cout << "No solution." << endl;
	}
	
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
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