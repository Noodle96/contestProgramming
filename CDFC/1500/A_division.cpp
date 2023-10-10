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
void solve(){
	ll p,q; cin>>p>>q;
	set<ll> DC_q;
	ll copy_q = q;
	//DESCOMPOSICION CANONICA DE Q
	for(ll i = 2 ; i*i <= q ; i++){
		if(q%i == 0){
			while(q%i == 0){
				q /= i;
			}
			DC_q.insert(i);
		}
	}
	if(q > 1) DC_q.insert(q);

	ll best = 0;
	for(auto e:DC_q){
		ll temp_p = p;
		while(temp_p % copy_q  == 0) temp_p /= e;
		best = max(best, temp_p); 
	}
	cout <<best << endl;

}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
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