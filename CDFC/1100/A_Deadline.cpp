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
double d;
double f(double x){
	return (x*x + x + d)/ (x+1);
}

double ternary_search(double l, double r) {
    double eps = 1e-9;              //set the error limit here
    while (r - l > eps) {
		// cout << "[" << l<< ":" << r << "]" <<  endl;
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
		// cout << "m1: " << m1 << " m2: " << m2 << endl;
        double f1 = f(m1);      //evaluates the function at m1
        double f2 = f(m2);      //evaluates the function at m2
		// cout << "f1: " << f1 << " f2: " << f2 << endl;
        if (f1 > f2)
            l = m1;
        else
            r = m2;
    }
    return f(l);
}
void solve(){
	double n;
	cin>>n>>d;
	if(d<=n){cout << "YES" << endl; return;}
	double ans =  ternary_search(0.0,d);

	double parteEntera = floor(ans);

	if((ans-parteEntera) < 1e-10){ // ejm : 3.0
		// cout << "ans: " << ans << endl;
		if( floor(ans)>n) cout << "NO" << endl; // floor(3.0) = 3
		else cout << "YES" << endl;
	}else{ // ejm: 3.21
		int answer = ceil(ans);
		if( answer>n) cout << "NO" << endl;
		else cout << "YES" << endl;
	}

	// cout << "ans: " << ans << endl;
	// cout << "ceil" << ceil(ans) << endl;
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