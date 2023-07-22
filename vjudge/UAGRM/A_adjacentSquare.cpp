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
	int row, col; cin>>row>>col;
	int r,c; cin>>r>>c;
	int cont = 0;
	if( r-1 >=1 && r-1 <= row) cont++;
	if(r+1 >= 1 && r+1<= row) cont++;
	if(c-1 >= 1 && c-1 <= col) cont++;
	if(c+1 >= 1 && c+1 <= col)cont++;
	cout << cont << endl; 
}
int main(){
	solve();
	return 0;
}