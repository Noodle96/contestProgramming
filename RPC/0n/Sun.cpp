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

void solve(){
	int a,b,c,d; cin>>a>>b>>c>>d;
	map<int, int> mapa;
	if(d<=b){
		int dif = d-c;
		mapa[dif] = 1;
		dif+=d;
		while(dif <= 5250){
			mapa[dif] = 1;
			dif+= d;
		}
		int r = b-a;
		while(1){
			if( mapa.count(r) > 0 ){
				cout << r << endl;
				return;
			}
			r+=b;
		}
	}else{ //d>=b 
		int dif = b-a;
		mapa[dif] = 1;
		dif+= b;
		while(dif <= 5250){
			mapa[dif] = 1;
			dif+= b;
		}
		int r = d-c;
		while(1){
			if( mapa.count(r) > 0 ){
				cout << r << endl;
				return;
			}
			r+=d;
		}
	}
}
int main(){
	solve();
	return 0;
}