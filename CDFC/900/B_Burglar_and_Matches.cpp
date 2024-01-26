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
	ll n,m;
	cin>>n>>m;
	vector< pair<ll,ll> > vec(m);
	for(int e = 0 ; e < m; e++){
		cin>>vec[e].second>>vec[e].first;
	}
	sort(vec.begin(), vec.end(), [](pair<ll,ll> &pa, pair<ll,ll> &pb){
		return pa.first > pb.first;
	});
	//print vec
	// for(int e = 0 ; e < m; e++){
	// 	cout << vec[e].first << " " << vec[e].second << endl;
	// }	
	ll ans = 0 ;
	for(auto e: vec){
		if(e.second < n){
			n -= e.second;
			ans += e.second * e.first;
		}else{
			ans += (n* e.first);
			break;
		}
	}
	cout << ans << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifdef DEBUG
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	solve();
	return 0;
}