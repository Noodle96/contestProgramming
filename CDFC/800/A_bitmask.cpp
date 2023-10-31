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

int gcd(int a,int b){
	if(a%b==0) return b;
	else return gcd(b,a%b);
}

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

bool isPowerOfTwo(int n){
	return ceil(log2(n)) == floor(log2(n));
}

void solve(){
	bitset<32> rb;
	bitset<32> ans;
	int x; cin>>x;
	for(int e = 30; e >= 0 ; e--){
		if((x & (1<<e)) != 0) rb.set(e,1);
	}
	int selected;
	for(int e = 0 ; e <=30; e++){
		if(rb[e] == 1){ans.set(e,1); selected = e; break;}
	}
	// cout << rb << endl;
	// cout << ans << endl;
	if(!isPowerOfTwo(x)){
		cout << ans.to_ulong() << endl;
		return;
	}
	
	for(int e = 0 ; e <=30; e++){
		if(e != selected){
			ans.set(e, !ans[e]); break;
		}
	}
	// cout << "end" << endl;
	// cout << rb << endl;
	// cout << ans << endl;
	cout << ans.to_ulong() << endl;

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	// #ifndef IN_OUT
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
	
	int t; cin>>t;
	while(t--) solve();
	
	return 0;
}