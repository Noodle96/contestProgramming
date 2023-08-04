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
	int cont5 = 0, cont7 = 0;
	for(int e = 0, temp ; e < 3; e++){
		cin>>temp;
		if(temp == 5) cont5++;
		if(temp == 7) cont7++;
	}
	if(cont5 == 2 && cont7 == 1) cout << "YES\n";
	else cout << "NO\n";
}
int main(){
	solve();
	return 0;
}