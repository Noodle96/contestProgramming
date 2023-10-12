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
	int n,m,a,b; cin>>n>>m>>a>>b;
	if(float(a) <= float(b)/float(m)){
		cout << n*a << endl;
	}else{
		// a > b/m
		if(int(n)%int(m) == 0){
			cout << n*b/m << endl;
		}else{
			int left = b*(n/m +1);
			int right = b*(n/m) + a*(n%m);
			cout << min( left, right) << endl;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}