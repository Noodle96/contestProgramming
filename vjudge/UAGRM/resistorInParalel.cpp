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
	float sumaTotal=0.0;
	float temp;
	for(int  e = 0 ; e < n; e++){
		cin>>temp;
		sumaTotal += 1.0/temp;
	}
	msg(1.0/sumaTotal,"");
}
int main(){
	solve();
	return 0;
}