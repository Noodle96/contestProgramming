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
	int n,s,r; cin>>n>>s>>r;
	cout << s-r << " ";
	int restante = n-1;
	if(r%restante == 0){
		for(int e = 0 ; e < restante ; e++){
			cout << r/restante << " ";
		}cout << endl;
	}else{
		int a = r%restante;
		for(int e = 0 ;e < a ; e++){
			cout << (r/restante) +1 << " ";
		}
		for(int e = 0 ;e < (restante -a) ; e++){
			cout << r/restante << " ";
		}cout << endl;
	}
	
}
int main(){
	// #ifndef IN_OUT
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif

	int t; cin>>t;
	while(t--){
		solve();
	}

	return 0;
}