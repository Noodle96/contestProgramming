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
	int n,w; cin>>n>>w;
	vector<int> vec(n);
	for(int e = 0 ;e < n ; e++){
		cin>>vec[e];
	}
	map<int, int> mapa;
	//one
	for(int e = 0 ; e < n; e++){
		if(vec[e] <= w){
			mapa[vec[e]]++;
		}
	}
	//two
	for(int e = 0 ; e < n; e++){
		for(int j = e+1 ;j < n ; j++){
			if(   (vec[e] + vec[j]) <= w  ) mapa[vec[e]+vec[j]]++;
		}
	}
	//three
	for(int e = 0;  e< n; e++){
		for(int j = e+1 ;j < n ; j++){
			for(int k = j+1;k < n ; k++){
				if(  (vec[e]+vec[j]+vec[k])<=w ){
					mapa[vec[e]+vec[j]+vec[k]]++;
				}
			}
		}
	}
	cout << mapa.size() << endl;
}
int main(){
	solve();
	return 0;
}