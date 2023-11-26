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
const int N = 1e5;
int ar[N];
void solve(){
	int n; cin>>n;
	for(int e = 0 ; e < n; e++) cin>>ar[e];
	for(int e = 1 ; e < n; e++) ar[e] = ar[e-1]+ ar[e];
	// cout << "prefijo" << endl;
	// for(int e = 0 ; e < n; e++) cout << ar[e] << " ";
	// cout << endl;
	int m; cin>>m;
	for(int e = 0,temp ; e < m; e++){
		cin>>temp;
		auto lb = lower_bound(ar, ar+n, temp);
		auto position = lb-ar;
		// cout << "pos: " << position << endl;
		cout << position +1 << endl;
	}
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