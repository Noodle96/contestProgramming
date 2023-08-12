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
	int h,k,v,s; cin>>h>>k>>v>>s;
	int cont = 0;
	while(h > 0){
		v += s;
		v -= max(1,v/10);
		if(v>=k) h++;
		if(v<k && v>0) h--;
		if(h == 0) v = 0;
		if(v<=0){h= 0; v= 0;}
		cont += v;
		if(s>0) s--;
	}
	cout << cont << endl;
}
int main(){
	solve();
	return 0;
}