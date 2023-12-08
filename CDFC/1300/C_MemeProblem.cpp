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
	double d; cin>>d;
	if(d == 0){cout << "Y " << 0.0 << " " << 0.0 <<endl;return;}
	if(d < 4){cout << "N" << endl; return;}
	double b1,b2;
	double D = sqrt(d*d - 4 *d);
	b1 = (d + D)/2.0;
	// b2 = (d + D)/2.0;
	double a1,a2;
	a1 = d-b1;
	// a2 = d-b2;
	// printf("Y %.9lf %.9lf\n", a1,b1);
	cout << "Y " << a1 <<  " " << b1 << endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifdef DEBUG
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	cout << fixed << setprecision(9);
	int t; cin>>t;
	while(t--){
		solve();
	}
	
	return 0;
}