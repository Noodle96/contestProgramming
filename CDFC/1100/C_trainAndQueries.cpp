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
	map<int,vector<int>> map;
	//cin.ignore();
	string line; getline(cin,line);
	int n,k; cin>>n>>k;
	for(int e = 1,a; e <= n; e++){
		cin>>a;
		map[a].pb(e);
	}
	for(int e = 0,a,b ;e < k ; e++){
		cin>>a>>b;
		if(map.count(a)>0){
			if(map.count(b)>0){
				int positionA = *map[a].begin();
				int positionB = map[b].back();
				// cout << positionA << " " << positionB << endl;
				if(positionA<=positionB){
					cout << "YES" << endl;
				}else cout << "NO" << endl;
			}else{
				cout << "NO" << endl;
			}
		}else{
			cout << "NO" << endl;
		}
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