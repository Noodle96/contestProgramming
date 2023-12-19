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
const int N = 200200;
ll ar[N];
ll ar2[N];
ll ar3[N];
void solve(){
	int n; cin>>n;
	for(int e = 0 ; e < n; e++){
		cin>>ar[e];
		ar2[e] = ar[e];
		ar3[e] = ar[e];
	}
	sort(ar2, ar2+n);
	sort(ar3, ar3+n);
	for(int e = n-2; e>=0; e--){
		ar2[e] = ar2[e+1] +  ar2[e];
	}
	// cout << "ar1" << endl;
	// for(int e = 0; e < n; e++){
	// 	cout << ar[e] << " ";
	// }cout << endl;
	// cout << "ar2" << endl;
	// for(int e = 0; e < n; e++){
	// 	cout << ar2[e] << " ";
	// }cout << endl;
	// cout << "ar3" << endl;
	// for(int e = 0; e < n; e++){
	// 	cout << ar3[e] << " ";
	// }cout << endl;

	for(int e = 0 ;e <  n; e++){
		auto ub = upper_bound(ar3, ar3+n, ar[e]);
		int pos = ub-ar3;
		//cout << "pos: " << pos << endl;
		if(pos == n){
			cout << 0 << " ";
		}else{
			cout << ar2[pos] << " ";
		}
	}
	cout << endl;

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