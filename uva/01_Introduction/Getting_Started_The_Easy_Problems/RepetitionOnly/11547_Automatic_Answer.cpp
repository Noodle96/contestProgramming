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
	int n; cin>>n;
	n*= 567.0;
	n/=9.0;
	n+= 7492.0;
	n*=235.0;
	n/=47.0;
	n-=498.0;
	// cout << "n: " << n << endl;
	n = abs(n);
	int z = log10(n);
	while(n>=100){
		int ent = pow(10,z);
		n-= ((n/ent)*ent);
		z--;
	}

	// cout << "n: " << n << endl;
	// return;
	// n -= (( n/10)*10);
	cout << n/10 << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifdef DEBUG
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int t; cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}