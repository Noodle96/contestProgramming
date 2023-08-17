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
void print(int n, int limit){
	int limit2 = limit -1;
	for(int e = 0 ; e < n; e++){
		cout << "  ";
	}
	if(limit == 0){
		cout << 0;
	}else{
		for(int e = 0 ; e <=limit ; e++){
			cout << e << " ";
		}
	}
	
	int e = limit2;
	for( ; e > 0 ; e--){
		cout << e << " "  ;
	}
	if(e != -1) cout << e;
	cout << endl;
	// for(int e = 0 ; e < n; e++){
	// 	cout << "**";
	// }
	// cout << endl;
}
void solve(){
	int n; cin>>n;
	int n_ = n;
	int n2_ = n-1;
	for(int e = 0 ; e <= n; e++){
		print(n_,e);
		n_--;
	}
	int last = 1;
	for(int e = n2_ ;e >= 0 ; e--){
		print(last,e );
		last++;
	}
	
}
int main(){
	solve();
	return 0;
}