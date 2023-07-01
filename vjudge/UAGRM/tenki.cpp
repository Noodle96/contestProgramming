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
	string S,T;
	cin>>S>>T;
	int cont = 0 ;
	for(int e = 0 ;e < 3 ; e++){
		if(S[e] == T[e]) cont++;
	}
	msg(cont,"");
}
int main(){
	solve();
	return 0;
}