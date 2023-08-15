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

int n;
vector<int> pointXaxis;

float calculateArea(int i,int j){
	return (pointXaxis[j]-pointXaxis[i])/2.0;
}

void solve(){
	cin>>n;
	pointXaxis.resize(n);
	map<float, int> mapa;
	for(int e = 0 ; e < n; e++)cin>>pointXaxis[e];
	float area;
	for(int e = 0 ; e < n; e++){
		for(int j = e+1 ; j < n; j++){
			area = calculateArea(e,j);
			mapa[area]++;
		}
	}
	// msg("print mapa","");
	// for(auto it = mapa.begin(); it != mapa.end() ; it++){
	// 	cout << it->first << " : " << it->second << endl;
	// }
	cout << mapa.size() << endl;
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