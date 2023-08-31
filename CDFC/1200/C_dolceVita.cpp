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

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}
void solve(){
	int n; cin>>n;
	ll x; cin>>x;
	vector<ll> vec(n);
	for(int e = 0 ; e < n; e++)cin>>vec[e];
	sort(all(vec));
	for(int e =  1 ; e < n; e++){
		vec[e] = vec[e-1] + vec[e];
	}
	ll cont = 0;
	for(int e = 0 ; e < n ;e++){
		if(vec[e] > x) break;
		else{
			if((x-vec[e] +1)%(e+1) == 0)  cont += (x-vec[e] +1)/(e+1); 
			else cont += ((x-vec[e] +1)/(e+1)) +1 ;
		}
	}
	cout << cont << endl;
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