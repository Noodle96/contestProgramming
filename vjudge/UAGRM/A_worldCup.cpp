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
	int y; cin>>y;
	if(y%4 == 2){
		cout << y << endl;
	}else if(y%4 == 3){
		cout <<  y +3 << endl;
	}else if(y%4 == 0){
		cout << y + 2 << endl;
	}else if(y%4 == 1){
		cout << y +1 << endl;
	}else{
		cout << y << endl;
	}
}
int main(){
	solve();
	return 0;
}