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

struct Point2d{
	double x,y;
	Point2d(){}; // default constructor
	Point2d(int x_, int y_){x = x_, y = y_;}
};

double distance(Point2d &p1, Point2d &p2){
	return hypot(p1.x-p2.x, p1.y-p2.y);
}

void solve(){
	cout << setprecision(2) << fixed;
	Point2d center(0,0);
	Point2d p1;
	double r;
	cin>>p1.x>>p1.y>>r;
	double d = distance(center,p1);
	double minima, maxima;
	minima = r-d;
	maxima = r+d;
	cout << minima << " " << maxima << endl;
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