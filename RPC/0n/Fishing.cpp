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

map< int,vector<int> >mapa;


int calculate(int x, int y, int s){
	int total = 0;
	int topex = x+s;
	for(int e = x ; e <= topex ;e++){
		if(mapa.count(e) > 0){
			for(auto it = mapa[e].begin() ;it != mapa[e].end() ; it++){
				if(*it >= y && *it <= y+s ) total++;
			}
		}	
	}
	return total;
}

void solve(){
	int s,n; cin>>s>>n;
	// cout << s << " " << n << endl;
	for(int e = 0,x,y ;e < n ;e++){
		cin>>x>>y;
		mapa[x].pb(y);
	}
	

	//recorrer el mapa
	int total = 0;
	for(int e = 0 ; e <=100 ;e++){
		for(int j = 0 ; j <= 100; j++){
			// cout << "final " << endl;
			total = max(total,calculate(e,j,s));
		}
	}
	cout << total << endl;
}
int main(){
	// #ifndef IN_OUT
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
	solve();
	return 0;
}