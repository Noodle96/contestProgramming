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
	map<string, int> mapa;
	string str; int value;
	int maximo = INT_MIN;
	int indice = 0;
	for(int e = 0 ; e < n; e++){
		cin>>str>>value;
		if(mapa.count(str)>0){
			continue;
		}else{
			mapa[str] = value;
			if(value > maximo){
				maximo = value;
				indice = e+1;
			}
		}
	}
	cout << indice << endl;
}
int main(){
	solve();
	return 0;
}